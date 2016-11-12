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
    private:
        Group *_group;
    };
}
#endif /* SCENE_H */

