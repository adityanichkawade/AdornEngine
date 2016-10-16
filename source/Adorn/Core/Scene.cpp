/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Scene.cpp
 * Author: Aditya
 * 
 * Created on September 23, 2016, 10:17 PM
 */

#include <Adorn/Core/Node.h>
#include <Adorn/Core/Scene.h>
#include <Adorn/Core/Group.h>

#include <GL/glew.h>
#include <cstdlib>

namespace Adorn{
    Scene::Scene(): 
    _group(NULL){
        
        _clearColor[0] = 0.0f; 
        _clearColor[1] = 0.0f;
        _clearColor[2] = 0.0f;
        _clearColor[3] = 1.0f;
        
        this->_group = new Group();
    }

    Scene::~Scene() {
        if(this->_group != NULL){
            delete this->_group;
            this->_group = NULL;
        }
    }
    
    void Scene::addNode(Node* aNode){
        if(this->_group != NULL){
            this->_group->addNode(aNode);
        }
    }
    
    void Scene::render(){
        glClearBufferfv(GL_COLOR, 0, this->_clearColor);
        this->_group->render();
    }
    
    void Scene::setClearColor(float aClearColor[]){
        this->_clearColor[0] = aClearColor[0];
        this->_clearColor[1] = aClearColor[1];
        this->_clearColor[2] = aClearColor[2];
        this->_clearColor[3] = aClearColor[3];
    }
}

