#include <Adorn/Renderer/OpenGL/OpenGLPrimitive.h>
#include <GL/glew.h>

namespace Adorn {
	OpenGLPrimitive::OpenGLPrimitive(){
	}
	
	OpenGLPrimitive::~OpenGLPrimitive(){
	}

	void OpenGLPrimitive::render(){
		GLenum primitiveType;

		switch (_primitiveType) {
		case TRIANGLE_FAN:
			primitiveType = GL_TRIANGLE_FAN;
			break;
		default:
			primitiveType = GL_TRIANGLE_STRIP;
			break;
		}

		glDrawArrays(primitiveType, this->_startIndex, this->_indexCount);
	}
}