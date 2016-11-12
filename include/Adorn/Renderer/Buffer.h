#ifndef BUFFER_H
#define BUFFER_H

#include <iostream>
#include <vector>

namespace Adorn {
	class VertexAttribute;
	class BufferAttribute;
	class Primitive;

	typedef std::vector<VertexAttribute> VertexAttributeList;
	typedef std::vector<BufferAttribute> BufferAttributeList;

	class VertexAttribute {
	public:
		enum VertexAttributeType {
			POSITION,
			NORMAL,
			TEXCOORD,
			COLOR
		};
		VertexAttribute(VertexAttributeType aType, unsigned int aDataIndex, unsigned int aSize, unsigned int aStride, unsigned int aOffset);

		VertexAttributeType getType() const;
		unsigned int getDataIndex() const;
		unsigned int getStride() const;
		unsigned int getOffset() const;
		unsigned int getSize() const;
	private:
		VertexAttributeType _type;
		unsigned int _dataIndex;
		unsigned int _stride;
		unsigned int _offset;
		unsigned int _size;
	};

	class BufferAttribute {
	public:
		enum BufferType {
			VERTEX,
			INDEX
		};

		enum BufferUsage {
			STATIC,
			DYNAMIC
		};

		BufferAttribute();
		BufferAttribute(BufferType aBufferType, void *aBufferData, unsigned int aBufferSize, BufferUsage aBufferUsage);
		
		void addVertexAttribute(VertexAttribute &aVertexAttribute);
		VertexAttributeList getVertexAttributes();

		void setBufferType(BufferType aBufferType);
		void setBufferData(void *aBufferData);
		void setBufferSize(unsigned int aBufferSize);
		void setBufferUsage(BufferUsage aBufferUsage);

		BufferType getBufferType() const;
		BufferUsage getBufferUsage() const;
		unsigned int getBufferSize() const;
		void *getBufferData() const;
	private:
		BufferType _bufferType;
		BufferUsage _bufferUsage;
		void *_bufferData;
		unsigned int _bufferSize;
		VertexAttributeList _vertexAttributeList;
	};

	class Buffer {
	public:
		virtual ~Buffer();
		virtual void render() = 0;
		void setPrimitive(Primitive *aPrimitive);
		void addBufferAttribute(BufferAttribute &aBufferAttribute);
		BufferAttributeList getBufferAttributes();

	protected:
		Buffer();
		virtual void compile() = 0;
		BufferAttributeList _bufferAttributeList;
		bool _isCompiled;
		Primitive *_primitive;
	};
}

#endif // !BUFFER_H
