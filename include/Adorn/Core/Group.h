#ifndef GROUP_H
#define GROUP_H

#include <Adorn/Core/Node.h>
#include <vector>

namespace Adorn{
    class Group : public Node {
    public:
        Group();
        virtual ~Group();
        
        void render();
        void addNode(Node *aNode);
    private:
        void deleteNodes();
        std::vector<Adorn::Node*> _nodes;
    };
}
#endif /* GROUP_H */

