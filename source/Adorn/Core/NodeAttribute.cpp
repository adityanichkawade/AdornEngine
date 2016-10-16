/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Renderer.cpp
 * Author: Aditya
 * 
 * Created on September 23, 2016, 10:18 PM
 */

#include <cstdlib>

#include <Adorn/Core/NodeAttribute.h>
#include <Adorn/Renderer/ShaderProgram.h>
#include <Adorn/Renderer/Primitive.h>

namespace Adorn{
    NodeAttribute::NodeAttribute(): 
    _shaderProgram(NULL),
    _shape(NULL){
    }

    NodeAttribute::~NodeAttribute() {
        if(this->_shaderProgram != NULL){
            delete _shaderProgram;
            _shaderProgram = NULL;
        }
        
        if(this->_shape != NULL){
            delete _shape;
            _shape = NULL;
        }
    }

    void NodeAttribute::setShader(ShaderProgram* aShaderProgram) {
        this->_shaderProgram = aShaderProgram;
    }
    
    void NodeAttribute::setShape(Primitive *aShape){
        this->_shape = aShape;
    }
    
    void NodeAttribute::render(){
        if(this->_shaderProgram != NULL){
            this->_shaderProgram->render();
        }
        
        if(this->_shaderProgram != NULL){
            this->_shape->render();
        }
    }
}
