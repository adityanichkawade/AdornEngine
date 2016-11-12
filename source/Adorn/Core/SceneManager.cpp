#include <Adorn/Core/SceneManager.h>
#include <Adorn/Core/Scene.h>

namespace Adorn{
    SceneManager::SceneManager() {
    }

    SceneManager::~SceneManager() {
		for (size_t i = 0; i < _scene.size(); i++) {
			delete _scene[i];
		}

		_scene.clear();
    }
	void SceneManager::addScene(Scene * aScene) {
		this->_scene.push_back(aScene);
	}

	void SceneManager::renderScene()
	{
	}
}

