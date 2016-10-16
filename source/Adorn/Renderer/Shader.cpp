/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Shader.cpp
 * Author: Aditya
 * 
 * Created on September 23, 2016, 10:16 PM
 */

#include <Adorn/Renderer/Shader.h>
#include <cstdlib>

namespace Adorn {

    Shader::Shader(ShaderType aType):
    _shaderType(aType),
    _shaderSource(NULL) {
    }

    Shader::~Shader() {
	}
    
	void Shader::setShaderType(ShaderType aShaderType) {
		this->_shaderType = aShaderType;
	}

	Shader::Shader():
	_shaderType(VERTEX),
	_shaderSource(NULL){
	}
}

