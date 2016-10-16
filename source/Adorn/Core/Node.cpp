/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.cpp
 * Author: Aditya
 * 
 * Created on September 23, 2016, 10:16 PM
 */

#include <cstdlib>

#include <Adorn/Core/Node.h>
#include <Adorn/Core/NodeAttribute.h>

namespace Adorn{
    Node::Node():
    _attribute(NULL){
    }

    Node::~Node() {
        if(_attribute != NULL){
            delete _attribute;
            _attribute = NULL;
        }
    }
    
    void Node::setAttribute(NodeAttribute *aAttribute){
        _attribute = aAttribute;
    }
            
    void Node::render(){
        if(_attribute != NULL){
            _attribute->render();
        }
    }
}
