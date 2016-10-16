#ifndef NODE_H
#define NODE_H

namespace Adorn{
    class NodeAttribute;

    class Node {
    public:
        Node();
        virtual ~Node();

        void setAttribute(NodeAttribute *aAttribute);
        virtual void render();
    private:
        NodeAttribute *_attribute;
    };
}

#endif /* NODE_H */

