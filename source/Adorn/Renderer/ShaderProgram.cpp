/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ShaderProgram.cpp
 * Author: Aditya
 * 
 * Created on September 23, 2016, 10:17 PM
 */


#include <Adorn/Renderer/Shader.h>
#include <Adorn/Renderer/ShaderProgram.h>

#include <GL/glew.h>
#include <iostream>

namespace Adorn {

    ShaderProgram::ShaderProgram():
    _isCompiled(false){
    }

    ShaderProgram::~ShaderProgram() {
        this->releaseShaders();
    }

	bool ShaderProgram::attach(Shader *aShader) {
		this->_shaders.push_back(aShader);
		return true;
	}
    
    void ShaderProgram::releaseShaders(){
        for(size_t i = 0; i < this->_shaders.size(); i++){
            delete this->_shaders[i];
        }
    }
}

