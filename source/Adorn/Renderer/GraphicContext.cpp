#include <Adorn/Renderer/GraphicContext.h>
#include <Adorn/Renderer/OpenGL/OpenGLContext.h>
#include <Adorn/Renderer/RenderFactory.h>
#include <Adorn/Core/Scene.h>

namespace Adorn {

	void GraphicContext::setScene(Scene * aScene){
		this->_scene = aScene;
	}

	void GraphicContext::setClearColor(float aColor[]){
		this->_clearColor[0] = aColor[0];
		this->_clearColor[1] = aColor[1];
		this->_clearColor[2] = aColor[2];
		this->_clearColor[3] = aColor[3];
	}

	void GraphicContext::render()
	{
		this->begin();
		this->_scene->render();
		this->end();
	}

	GraphicContext::GraphicContext():
		_rendererFactory(NULL){
	}

	GraphicContext::~GraphicContext(){
		if (this->_scene) {
			delete this->_scene;
		}
		if (this->_rendererFactory) {
			delete this->_rendererFactory;
		}
	}

	GraphicContext * GraphicContext::create(GraphicContextType aGraphicContextType) {
		GraphicContext *graphicContext = NULL;
		
		switch (aGraphicContextType) {
			case GraphicContext::OPENGL:
				graphicContext = new OpenGLContext();
		}

		return graphicContext;
	}
}
