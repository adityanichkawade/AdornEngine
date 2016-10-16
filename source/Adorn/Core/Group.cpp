/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Group.cpp
 * Author: Aditya
 * 
 * Created on September 23, 2016, 10:16 PM
 */

#include <Adorn/Core/Node.h>
#include <Adorn/Core/Group.h>
#include <cstdlib>

namespace Adorn{
    Group::Group() {
    }

    Group::~Group() {
        this->deleteNodes();
    }
    
    void Group::addNode(Node* aNode){
        this->_nodes.push_back(aNode);
    }
    
    void Group::render(){
        for(size_t i = 0; i < this->_nodes.size(); i++){
            this->_nodes[i]->render();
        }
        
        this->_nodes.clear();
    }
    
    void Group::deleteNodes(){
        for(size_t i = 0; i < this->_nodes.size(); i++){
            delete this->_nodes[i];
        }
    }
}

