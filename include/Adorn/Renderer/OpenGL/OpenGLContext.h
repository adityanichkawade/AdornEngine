#ifndef OPENGL_CONTEXT_H
#define OPENGL_CONTEXT_H

#include <Windows.h>
#include <Adorn/Renderer/GraphicContext.h>

namespace Adorn {
	class OpenGLContext : public GraphicContext {
	public:
		OpenGLContext();
		~OpenGLContext();

		RenderFactory *getRenderFactory();
		bool setupContext(HWND aHWnd);

		void begin();
		void end();
	private:
		HGLRC _hRC;
		HDC	  _hDC;
	};
}

#endif // !1
