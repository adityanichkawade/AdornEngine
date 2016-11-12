#include <Adorn/Renderer/OpenGL/OpenGLPrimitive.h>
#include <Adorn/Renderer/OpenGL/OpenGLShader.h>
#include <Adorn/Renderer/OpenGL/OpenGLBuffer.h>
#include <Adorn/Renderer/OpenGL/OpenGLShaderProgram.h>
#include <Adorn/Renderer/OpenGL/OpenGLRenderFactory.h>

namespace Adorn {
	Shader * OpenGLRenderFactory::createShader() {
		return new OpenGLShader();
	}

	Primitive *OpenGLRenderFactory::createPrimitive() {
		return new OpenGLPrimitive();
	}

	Buffer * OpenGLRenderFactory::createBuffer()
	{
		return new OpenGLBuffer();
	}

	ShaderProgram * OpenGLRenderFactory::createShaderProgram()
	{
		return new OpenGLShaderProgram();
	}
	
	OpenGLRenderFactory::OpenGLRenderFactory()
	{
	}
	
	OpenGLRenderFactory::~OpenGLRenderFactory()
	{
	}
}
