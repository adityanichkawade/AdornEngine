#ifndef OPENGL_RENDER_FACTORY_H
#define OPENGL_RENDER_FACTORY_H

#include <Adorn/Renderer/RenderFactory.h>

namespace Adorn {
	class OpenGLRenderFactory : public RenderFactory {
	public:
		OpenGLRenderFactory();
		~OpenGLRenderFactory();

		Shader *createShader();
		Primitive *createPrimitive();
	};
}

#endif