#include <Adorn/Renderer/OpenGL/OpenGLBuffer.h>
#include <GL/glew.h>

namespace Adorn {
	OpenGLBuffer::OpenGLBuffer():
		_bufferId(0){
	}

	OpenGLBuffer::~OpenGLBuffer(){
	}

	void OpenGLBuffer::render(){
		if (this->_attributeChanged == true) {
			this->compile();
			this->_attributeChanged = false;
		}


	}

	void OpenGLBuffer::compile(){
		GLenum bufferType = this->getBufferType();
		GLenum bufferUsage = this->getBufferUsage();

		glGenBuffers(1, &_bufferId);

		glBindBuffer(bufferType, _bufferId);
		glBufferData(bufferType, this->_bufferSize, this->_data, bufferUsage);
		glBindBuffer(bufferType, 0);
	}

	GLenum OpenGLBuffer::getBufferType() const{
		if (this->getBufferType == Buffer::INDEX) {
			return GL_ELEMENT_ARRAY_BUFFER;
		}

		return GL_ARRAY_BUFFER;
	}

	GLenum OpenGLBuffer::getBufferUsage() const {
		if (this->_bufferUsage == Buffer::DYNAMIC) {
			return GL_DYNAMIC_DRAW;
		}
		return GL_STATIC_DRAW;
	}
}

