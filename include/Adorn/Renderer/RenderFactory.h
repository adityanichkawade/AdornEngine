#ifndef  RENDER_FACTORY_H
#define  RENDER_FACTORY_H

namespace Adorn {
	class Shader;
	class Primitive;
	class Buffer;
	class ShaderProgram;

	class RenderFactory {
	public:
		virtual ~RenderFactory();
		virtual Shader *createShader() = 0;
		virtual ShaderProgram *createShaderProgram() = 0;
		virtual Primitive *createPrimitive() = 0;
		virtual Buffer *createBuffer() = 0;
	protected:
		RenderFactory();
	};
}

#endif // ! RENDER_FACTORY_H
