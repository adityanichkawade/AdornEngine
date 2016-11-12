#ifndef OPENGL_BUFFER_H
#define OPENGL_BUFFER_H

#include <Adorn/Renderer/Buffer.h>
#include <vector>
#include <GL/glew.h>

namespace Adorn {
	class OpenGLBuffer : public Buffer{
	public:
		OpenGLBuffer();
		~OpenGLBuffer();
		void render();
	protected:
		void compile();
	private:
		GLenum getBufferType(BufferAttribute::BufferType aBufferType) const;
		GLenum getBufferUsage(BufferAttribute::BufferUsage aBufferUsage) const;

		unsigned int _vao;
		std::vector<unsigned int>  _bufferIds;
	};
}

#endif // !OPENGL_BUFFER_H
