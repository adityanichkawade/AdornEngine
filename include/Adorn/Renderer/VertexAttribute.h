#ifndef VERTEX_ATTRIBUTE_H
#define VERTEX_ATTRIBUTE_H

namespace Adorn {
	class VertexAttribute {
		enum VertexAttributeType {
			POSITION,
			NORMAL,
			TEXCOORD,
			COLOR
		};
	public:
		VertexAttribute(VertexAttributeType aType, 
						unsigned int aDataIndex, 
						unsigned int aSize, 
						unsigned int aStride, 
						unsigned int aOffset);
		
		VertexAttributeType getType();
		unsigned int getDataIndex();
		unsigned int getStride();
		unsigned int getOffset();
		unsigned int getSize();
	private:
		VertexAttributeType _type;
		unsigned int _dataIndex;
		unsigned int _stride;
		unsigned int _offset;
		unsigned int _size;
	};
};

#endif // !VERTEX_ATTRIBUTE_H
