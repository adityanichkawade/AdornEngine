#include <Adorn/Renderer/Buffer.h>
#include <Adorn/Renderer/Primitive.h>

namespace Adorn{
	Buffer::~Buffer(){
	}

	void Buffer::setPrimitive(Primitive * aPrimitive){
		this->_primitive = aPrimitive;
	}

	void Buffer::addBufferAttribute(BufferAttribute & aBufferAttribute){
		this->_bufferAttributeList.push_back(aBufferAttribute);
	}

	BufferAttributeList Buffer::getBufferAttributes(){
		return this->_bufferAttributeList;
	}

	Buffer::Buffer():
		_isCompiled(false){
	}

	VertexAttribute::VertexAttribute(VertexAttributeType aType, unsigned int aDataIndex, unsigned int aSize, unsigned int aStride, unsigned int aOffset):
	_type(aType),
	_dataIndex(aDataIndex),
	_size(aSize),
	_stride(aStride),
	_offset(aOffset)
	{
	}

	VertexAttribute::VertexAttributeType VertexAttribute::getType() const{
		return this->_type;
	}

	unsigned int VertexAttribute::getDataIndex() const{
		return this->_dataIndex;
	}

	unsigned int VertexAttribute::getStride() const{
		return this->_stride;
	}

	unsigned int VertexAttribute::getOffset() const{
		return this->_offset;
	}

	unsigned int VertexAttribute::getSize() const {
		return this->_size;
	}

	BufferAttribute::BufferAttribute() :
		_bufferType(VERTEX),
		_bufferData(NULL),
		_bufferSize(0),
		_bufferUsage(STATIC)
	{
	}

	BufferAttribute::BufferAttribute(BufferType aBufferType, void * aBufferData, unsigned int aBufferSize, BufferUsage aBufferUsage):
	_bufferType(aBufferType),
	_bufferData(aBufferData),
	_bufferSize(aBufferSize),
	_bufferUsage(aBufferUsage)
	{
	}

	void BufferAttribute::addVertexAttribute(VertexAttribute  &aVertexAttribute){
		this->_vertexAttributeList.push_back(aVertexAttribute);
	}

	VertexAttributeList BufferAttribute::getVertexAttributes(){
		return this->_vertexAttributeList;
	}

	void BufferAttribute::setBufferType(BufferType aBufferType)
	{
		this->_bufferType = aBufferType;
	}

	void BufferAttribute::setBufferData(void * aBufferData)
	{
		this->_bufferData = aBufferData;
	}

	void BufferAttribute::setBufferSize(unsigned int aBufferSize)
	{
		this->_bufferSize = aBufferSize;
	}

	void BufferAttribute::setBufferUsage(BufferUsage aBufferUsage){
		this->_bufferUsage = aBufferUsage;
	}

	BufferAttribute::BufferType BufferAttribute::getBufferType() const {
		return this->_bufferType;
	}

	BufferAttribute::BufferUsage BufferAttribute::getBufferUsage() const {
		return this->_bufferUsage;
	}

	unsigned int BufferAttribute::getBufferSize() const {
		return this->_bufferSize;
	}
	void * BufferAttribute::getBufferData() const{
		return _bufferData;
	}
}
