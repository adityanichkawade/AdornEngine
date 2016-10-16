#include <Adorn/Renderer/OpenGL/OpenGLShader.h>
#include <GL/glew.h>
#include <cstdlib>

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
		if (this->_shaderId != 0) {
			glCompileShader(this->_shaderId);
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

