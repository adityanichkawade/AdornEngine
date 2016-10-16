#ifndef OPENGL_PRIMITIVE_H
#define OPENGL_PRIMITIVE_H

#include <Adorn/Renderer/Primitive.h>
namespace Adorn {

	class OpenGLPrimitive : public Primitive {
	public:
		OpenGLPrimitive();
		~OpenGLPrimitive();
		
		void render(); 
	};
};

#endif // !OPENGL_PRIMITIVE_H
