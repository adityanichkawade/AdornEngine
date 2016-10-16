#include <Adorn/Renderer/OpenGL/OpenGLContext.h>
#include <Adorn/Renderer/OpenGL/OpenGLRenderFactory.h>

#include <GL/glew.h>
#include <GL/wglew.h>


namespace Adorn {
	OpenGLContext::OpenGLContext(){
	}

	OpenGLContext::~OpenGLContext(){
	}

	RenderFactory * OpenGLContext::getRenderFactory()
	{
		if (this->_rendererFactory == NULL) {
			this->_rendererFactory = new OpenGLRenderFactory();
		}

		return this->_rendererFactory;
	}

	bool OpenGLContext::setupContext(HWND aHWnd){
		
		this->_hDC = GetDC(aHWnd);   

		PIXELFORMATDESCRIPTOR pfd;   
		memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));   
		pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);   
		pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;   
		pfd.iPixelType = PFD_TYPE_RGBA;   
		pfd.cColorBits = 32;   
		pfd.cDepthBits = 32;   
		pfd.iLayerType = PFD_MAIN_PLANE;   

		int nPixelFormat = ChoosePixelFormat(this->_hDC, &pfd); 
		if (nPixelFormat == 0) 
			return false;

		BOOL bResult = SetPixelFormat(this->_hDC, nPixelFormat, &pfd);   
		if (!bResult) 
			return false;

		HGLRC tempOpenGLContext = wglCreateContext(this->_hDC);   
		wglMakeCurrent(this->_hDC, tempOpenGLContext);   

		GLenum error = glewInit();   
		if (error != GLEW_OK)   
			return false;

		int attributes[] = {
			WGL_CONTEXT_MAJOR_VERSION_ARB, 3,  
			WGL_CONTEXT_MINOR_VERSION_ARB, 2,   
			WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,  
			0
		};

		if (wglewIsSupported("WGL_ARB_create_context") == 1) { 
			this->_hRC = wglCreateContextAttribsARB(this->_hDC, NULL, attributes);   
			wglMakeCurrent(NULL, NULL);   
			wglDeleteContext(tempOpenGLContext);   
			wglMakeCurrent(this->_hDC, this->_hRC);   
		}
		else {
			this->_hRC = tempOpenGLContext;   
		}

		return true; 
	}
	void OpenGLContext::begin(){
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
		glClearColor(this->_clearColor[0], this->_clearColor[1], this->_clearColor[2], this->_clearColor[3]);
	}

	void OpenGLContext::end(){
		SwapBuffers(this->_hDC);
	}
}
