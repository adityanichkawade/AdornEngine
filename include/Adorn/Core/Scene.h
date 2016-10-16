#ifndef SCENE_H
#define SCENE_H

#include <vector>

namespace Adorn{
    class Group;
    class Node;

    class Scene {
    public:
        Scene();
        virtual ~Scene();

        void addNode(Node *aNode);
        void render();
        void setClearColor(float aClearColor[]);
    private:
        Group *_group;
        float _clearColor[4];
    };
}
#endif /* SCENE_H */

