#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <vector>

namespace Adorn{
    class Scene;
    
    class SceneManager {
    public:
        SceneManager();
        virtual ~SceneManager();

		void addScene(Scene* aScene);
        
        void renderScene();
    private:
        std::vector<Scene*> _scene;
    };
}
#endif /* SCENEMANAGER_H */

