#include <Adorn/Renderer/OpenGL/OpenGLShader.h>
#include <Adorn/Renderer/OpenGL/OpenGLShaderProgram.h>
#include <GL/glew.h>

#include <iostream>

void _print_programme_info_log(GLuint sp) {
	int max_length = 2048;
	int actual_length = 0;
	char log[2048];
	glGetProgramInfoLog(sp, max_length, &actual_length, log);
	printf("program info log for GL index %i:\n%s", sp, log);
}

namespace Adorn {

	OpenGLShaderProgram::OpenGLShaderProgram() {
		this->createShaderProgram();
	}

	OpenGLShaderProgram::~OpenGLShaderProgram() {
	}

	bool OpenGLShaderProgram::attach(Shader* aShader = NULL) {
		if (aShader != NULL) {
			OpenGLShader *glShader = dynamic_cast<OpenGLShader*>(aShader);
			glAttachShader(this->_shaderProgram, glShader->getShaderId());
			ShaderProgram::attach(aShader);
			return true;
		}
		return false;
	}

	void OpenGLShaderProgram::createShaderProgram() {
		this->_shaderProgram = glCreateProgram();
	}

	void OpenGLShaderProgram::linkProgram() {
		glLinkProgram(this->_shaderProgram);
	}

	void OpenGLShaderProgram::useProgram() {
		glUseProgram(this->_shaderProgram);
	}

	void OpenGLShaderProgram::render() {
		if (this->_isCompiled == false) {
			this->linkProgram();
		}

		this->useProgram();
	}
}

