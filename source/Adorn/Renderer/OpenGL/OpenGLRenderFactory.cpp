#include <Adorn/Renderer/Shader.h>
#include <Adorn/Renderer/Primitive.h>


#include <Adorn/Renderer/OpenGL/OpenGLPrimitive.h>
#include <Adorn/Renderer/OpenGL/OpenGLShader.h>
#include <Adorn/Renderer/OpenGL/OpenGLRenderFactory.h>

namespace Adorn {
	Shader * OpenGLRenderFactory::createShader() {
		return new OpenGLShader();
	}

	Primitive *OpenGLRenderFactory::createPrimitive() {
		return new OpenGLPrimitive();
	}
	
	OpenGLRenderFactory::OpenGLRenderFactory()
	{
	}
	
	OpenGLRenderFactory::~OpenGLRenderFactory()
	{
	}
}
