#include <Adorn/Renderer/Buffer.h>

namespace Adorn{
	Buffer::~Buffer(){
	}

	void Buffer::setType(BufferType aBufferType){
		this->_bufferType = aBufferType;
		this->_attributeChanged = true;
	}

	void Buffer::setData(void *aBufferData, std::size_t aBufferSize) {
		this->_data = aBufferData;
		this->_bufferSize = aBufferSize;
		this->_attributeChanged = true;
	}

	void Buffer::setBufferUsage(BufferUsage aBufferUsage){
		this->_bufferUsage = aBufferUsage;
	}

	Buffer::Buffer():
	_bufferType(Buffer::VERTEX),
	_attributeChanged(true),
	_bufferId(0),
	_bufferSize(NULL),
	_bufferUsage(Buffer::STATIC){
	}
}
