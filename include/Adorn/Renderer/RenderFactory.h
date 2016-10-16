#ifndef  RENDER_FACTORY_H
#define  RENDER_FACTORY_H

namespace Adorn {
	class Shader;
	class Primitive;

	class RenderFactory {
	public:
		virtual ~RenderFactory();
		virtual Shader *createShader() = 0;
		virtual Primitive *createPrimitive() = 0;
	protected:
		RenderFactory();
	};
}

#endif // ! RENDER_FACTORY_H
