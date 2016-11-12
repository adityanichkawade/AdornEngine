#ifndef NODE_H
#define NODE_H

namespace Adorn{
    class Pipeline;

    class Node {
    public:
        Node();
        virtual ~Node();

        void setPipeline(Pipeline *aAttribute);
        virtual void render();
    private:
        Pipeline *_attribute;
    };
}

#endif /* NODE_H */

