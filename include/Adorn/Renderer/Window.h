#ifndef WINDOW_H_
#define WINDOW_H_

#include <Windows.h>

namespace Adorn {
	class GraphicContext;

	class Window {
	public:
		Window(LPCWSTR aTitle, unsigned int aWidth, unsigned int aHeight, HINSTANCE aHInstance);
		~Window();

		static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
		HWND getHandle();

		bool create();
		void show();
		bool isRunning();

		void setContext(GraphicContext *aContext);

		void run();
		
	private:
		GraphicContext * _context;
		unsigned int _width;
		unsigned int _height;
		HINSTANCE _hInstance;
		LPCWSTR _title;
		HWND _hWnd;
	};
}

#endif