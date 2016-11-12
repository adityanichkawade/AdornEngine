#include <Adorn/Core/Node.h>
#include <Adorn/Core/Scene.h>
#include <Adorn/Core/Group.h>

#include <GL/glew.h>
#include <cstdlib>

namespace Adorn{
    Scene::Scene(): 
    _group(NULL){

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
        this->_group->render();
    }
}

