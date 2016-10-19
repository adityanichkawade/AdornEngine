#include <Adorn/Renderer/Window.h>
#include <Adorn/Renderer/GraphicContext.h>
#include <Adorn/Renderer/RenderFactory.h>
#include <Adorn/Renderer/Shader.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR  lpCmdLine, int nCmdShow) {
	
	Adorn::Window *window = new Adorn::Window(L"Simple Window", 800, 600, hInstance);
	Adorn::GraphicContext *gc = Adorn::GraphicContext::create(Adorn::GraphicContext::OPENGL);
	Adorn::RenderFactory *renderFactory = gc->getRenderFactory();

	Adorn::Shader *shader = renderFactory->createShader();
	
	gc->setupContext(window->getHandle());
	
	float color[4] = { 0.0f, 1.0f, 0.0f, 1.0f };
	gc->setClearColor(color);

	window->show();

	while (window->isRunning()) {
		gc->begin();
		gc->end();
	}

	delete gc;
	delete window;

	return 0;
}