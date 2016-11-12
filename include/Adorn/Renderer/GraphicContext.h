#ifndef GRAPHIC_CONTEXT_H
#define GRAPHIC_CONTEXT_H

#include <Windows.h>

namespace Adorn {
	class Scene;
	class RenderFactory;

	class GraphicContext {
	public:
		enum GraphicContextType
		{
			OPENGL,
			DIRECTX
		};

		virtual ~GraphicContext();

		static GraphicContext *create(GraphicContextType aGraphicContextType);

		void setScene(Scene *aScene);
		void setClearColor(float aColor[]);
		
		virtual RenderFactory *getRenderFactory() = 0;
		virtual bool setupContext(HWND aHWnd) = 0;
		virtual void begin() = 0;
		virtual void end() = 0;

		void render();
	protected:
		GraphicContext();
	protected:
		Scene *_scene;
		RenderFactory *_rendererFactory;
		float _clearColor[4];
	};
}

#endif 
