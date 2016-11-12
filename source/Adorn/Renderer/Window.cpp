#include <Adorn/Renderer/Window.h>
#include <Adorn/Renderer/GraphicContext.h>

namespace Adorn {
	Window::Window(LPCWSTR aTitle, unsigned int aWidth, unsigned int aHeight, HINSTANCE aHInstance): 
		_width(aWidth),
		_height(aHeight),
		_title(aTitle),
		_hInstance(aHInstance),
		_hWnd(NULL),
		_context(NULL){
	}

	Window::~Window(){
		delete this->_context;
		DestroyWindow(this->_hWnd);
	}

	LRESULT Window::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
		switch (message) {
			case WM_SIZE: {
				break;
			}

			case WM_DESTROY: {
				PostQuitMessage(0);
				break;
			}
		}

		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	bool Window::create(){
		WNDCLASS windowClass;
		DWORD dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;

		this->_hInstance = GetModuleHandle(NULL);

		windowClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
		windowClass.lpfnWndProc = (WNDPROC)WndProc;
		windowClass.cbClsExtra = 0;
		windowClass.cbWndExtra = 0;
		windowClass.hInstance = this->_hInstance;
		windowClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
		windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
		windowClass.hbrBackground = NULL;
		windowClass.lpszMenuName = NULL;
		windowClass.lpszClassName = this->_title;

		if (!RegisterClass(&windowClass)) {
			return false;
		}

		this->_hWnd = CreateWindowEx(dwExStyle, this->_title, this->_title, WS_OVERLAPPEDWINDOW,
									 CW_USEDEFAULT, 0, this->_width, this->_height, NULL, NULL, this->_hInstance, NULL);

		if (this->_context) {
			this->_context->setupContext(this->_hWnd);
		}

		return true;
	}

	void Window::show(){
		ShowWindow(this->_hWnd, SW_SHOW);
		UpdateWindow(this->_hWnd);
	}

	bool Window::isRunning() {
		MSG msg;

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			if (msg.message == WM_QUIT) {
				return false;
			}
			
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		return true;
	}

	void Window::setContext(GraphicContext * aContext)
	{
		this->_context = aContext;
	}

	void Window::run()
	{
		while (this->isRunning()) {
			this->_context->render();
		}
	}

	HWND Window::getHandle(){
		return this->_hWnd;
	}
}
