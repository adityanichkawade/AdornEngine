/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Group.h
 * Author: Aditya
 *
 * Created on September 23, 2016, 10:16 PM
 */

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

