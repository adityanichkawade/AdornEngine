#include <Adorn/Renderer/VertexAttribute.h>
#include "Buffer.h"

namespace Adorn {
	VertexAttribute::VertexAttribute(VertexAttributeType aType,
									 unsigned int aDataIndex,
									 unsigned int aSize,
									 unsigned int aStride,
									 unsigned int aOffset):
									_type(aType),
									_stride(aStride),
									_offset(aOffset),
									_size(aSize),
									_dataIndex(aDataIndex){}

	VertexAttributeType VertexAttribute::getType() const
	{
		return VertexAttributeType();
	}

	VertexAttribute::VertexAttributeType VertexAttribute::getType() {
		return this->_type;
	}

	unsigned int VertexAttribute::getDataIndex(){
		return this->_dataIndex;
	}

	unsigned int VertexAttribute::getStride() {
		return this->_stride;
	}

	unsigned int VertexAttribute::getOffset() {
		return this->_offset;
	}
	unsigned int VertexAttribute::getSize(){
		return this->_size;
	}
}
