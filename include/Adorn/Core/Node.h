/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.h
 * Author: Aditya
 *
 * Created on September 23, 2016, 10:16 PM
 */

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

