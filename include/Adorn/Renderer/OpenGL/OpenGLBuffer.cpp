#include <Adorn/Renderer/OpenGL/OpenGLBuffer.h>
#include <Adorn/Renderer/Primitive.h>


namespace Adorn {
	OpenGLBuffer::OpenGLBuffer(){
	}

	OpenGLBuffer::~OpenGLBuffer(){
	}

	void OpenGLBuffer::render(){
		if (this->_isCompiled == false) {
			this->compile();
			this->_isCompiled = true;
		}

		glBindVertexArray(this->_vao);
		this->_primitive->render();
		glBindVertexArray(0);
	}

	void OpenGLBuffer::compile(){
		unsigned int bufferId;
		glGenVertexArrays(1, &this->_vao);

		glBindVertexArray(this->_vao);
		for (std::size_t i = 0; i < _bufferAttributeList.size(); i++) {

			BufferAttribute bufferAttribute = _bufferAttributeList[i];
			GLenum bufferType = this->getBufferType(bufferAttribute.getBufferType());
			GLenum bufferUsage = this->getBufferUsage(bufferAttribute.getBufferUsage());

			glGenBuffers(1, &bufferId);

			glBindBuffer(bufferType, bufferId);
			glBufferData(bufferType, bufferAttribute.getBufferSize(), bufferAttribute.getBufferData(), bufferUsage);
			//glBindBuffer(bufferType, 0);

			VertexAttributeList vertexAttributeList = bufferAttribute.getVertexAttributes();

			for (unsigned int i = 0; i < vertexAttributeList.size(); i++) {
				VertexAttribute va = vertexAttributeList[i];
				//glVertexAttribPointer(va.getDataIndex(), va.getSize(), GL_FLOAT, GL_FALSE, va.getStride(), (GLvoid*)va.getOffset());
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (GLvoid*)0);
				glEnableVertexAttribArray(va.getDataIndex());
			}
		}

		glBindVertexArray(0);
	}

	GLenum OpenGLBuffer::getBufferType(BufferAttribute::BufferType aBufferType) const{
		switch (aBufferType){
		case BufferAttribute::BufferType::INDEX:
			return GL_ELEMENT_ARRAY_BUFFER;
		default:
			return GL_ARRAY_BUFFER;
		}
	}

	GLenum OpenGLBuffer::getBufferUsage(BufferAttribute::BufferUsage aBufferUsage) const {
		switch (aBufferUsage)
		{
		case BufferAttribute::BufferUsage::DYNAMIC:
			return GL_DYNAMIC_DRAW;
		default:
			return GL_STATIC_DRAW;
		}
	}
}

