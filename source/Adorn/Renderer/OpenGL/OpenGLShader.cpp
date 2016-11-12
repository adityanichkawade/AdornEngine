#include <Adorn/Renderer/OpenGL/OpenGLShader.h>
#include <GL/glew.h>
#include <cstdlib>
#include <stdio.h>

/* print errors in shader compilation */
void _print_shader_info_log(GLuint shader_index) {
	int max_length = 2048;
	int actual_length = 0;
	char log[2048];
	glGetShaderInfoLog(shader_index, max_length, &actual_length, log);
	printf("shader info log for GL index %i:\n%s\n", shader_index, log);
}

namespace Adorn {
	OpenGLShader::OpenGLShader(){
	}

	OpenGLShader::OpenGLShader(ShaderType aType):
	Shader(aType),
	_shaderId(0){

	}

	OpenGLShader::~OpenGLShader() {
		if (this->_shaderId) {
			glDeleteShader(this->_shaderId);
		}
	}

	void OpenGLShader::setShaderSource(const char* aShaderSource) {
		if (aShaderSource != NULL) {
			this->createShader();
			if (this->_shaderId != 0) {
				glShaderSource(this->_shaderId, 1, &aShaderSource, NULL);
				this->compile();
			}
		}
	}

	unsigned int OpenGLShader::getShaderId() const {
		return this->_shaderId;
	}

	bool OpenGLShader::compile() {
		int params = -1;

		if (this->_shaderId != 0) {
			glCompileShader(this->_shaderId);

			/* check for compile errors */
			glGetShaderiv(this->_shaderId, GL_COMPILE_STATUS, &params);
			if (GL_TRUE != params) {
				fprintf(stderr, "ERROR: GL shader index %i did not compile\n", this->_shaderId);
				_print_shader_info_log(this->_shaderId);
				return 1; /* or exit or something */
			}
			return true;
		}
		return false;
	}

	void OpenGLShader::createShader() {
		switch (this->_shaderType) {
		case Shader::VERTEX:
			this->_shaderId = glCreateShader(GL_VERTEX_SHADER);
			break;
		case Shader::PIXEL:
			this->_shaderId = glCreateShader(GL_FRAGMENT_SHADER);
			break;
		}
	}
}

