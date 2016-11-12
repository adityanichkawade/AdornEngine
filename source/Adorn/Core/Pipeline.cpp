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

#include <Adorn/Core/Pipeline.h>
#include <Adorn/Renderer/ShaderProgram.h>
#include <Adorn/Renderer/Buffer.h>

namespace Adorn{
    Pipeline::Pipeline(): 
    _shaderProgram(NULL),
    _buffer(NULL){
    }

    Pipeline::~Pipeline() {
        if(this->_shaderProgram != NULL){
            delete _shaderProgram;
            _shaderProgram = NULL;
        }
        
        if(this->_buffer != NULL){
            delete _buffer;
            _buffer = NULL;
        }
    }

    void Pipeline::setShader(ShaderProgram* aShaderProgram) {
        this->_shaderProgram = aShaderProgram;
    }
    
    void Pipeline::setBuffer(Buffer *aBuffer){
        this->_buffer = aBuffer;
    }
    
    void Pipeline::render(){
        if(this->_shaderProgram != NULL){
            this->_shaderProgram->render();
        }
        
        if(this->_buffer != NULL){
            this->_buffer->render();
        }
    }
}
