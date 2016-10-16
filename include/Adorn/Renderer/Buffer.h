#ifndef BUFFER_H
#define BUFFER_H

#include <iostream>

namespace Adorn {
	class Buffer {
	public:
		enum BufferType {
			VERTEX,
			INDEX
		};

		enum BufferUsage{
			STATIC,
			DYNAMIC
		};

		virtual ~Buffer();
		virtual void render() = 0;
		
		void setType(BufferType aBufferType);
		void setData(void *aBufferData, std::size_t aBufferSize);
		void setBufferUsage(BufferUsage aBufferUsage);
	protected:
		Buffer();
		virtual void compile() = 0;

		BufferType _bufferType;
		BufferUsage _bufferUsage;
		void *_data;
		unsigned int _bufferId;
		std::size_t _bufferSize;
		bool _attributeChanged;
	};
}

#endif // !BUFFER_H
