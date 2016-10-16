#ifndef OPENGL_BUFFER_H
#define OPENGL_BUFFER_H

#include <Adorn/Renderer/Buffer.h>

namespace Adorn {
	class OpenGLBuffer : public Buffer{
	public:
		OpenGLBuffer();
		~OpenGLBuffer();
		void render();
	protected:
		void compile();
	private:
		GLenum getBufferType() const;
		GLenum getBufferUsage() const;

		unsigned int _bufferId;
	};
}

#endif // !OPENGL_BUFFER_H
