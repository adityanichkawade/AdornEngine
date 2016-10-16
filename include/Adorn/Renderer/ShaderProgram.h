/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ShaderProgram.h
 * Author: Aditya
 *
 * Created on September 23, 2016, 10:17 PM
 */

#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include <vector>

using namespace std;

namespace Adorn {
    
    class Shader;
    
    class ShaderProgram {
    public:
        ShaderProgram();
        virtual ~ShaderProgram();
        
        virtual bool attach(Shader *aShader);
        virtual void render() = 0;
		
	protected:
		bool _isCompiled;
    private:
        void releaseShaders();
    private:
		vector<Shader*> _shaders;
    };
};

#endif /* SHADERPROGRAM_H */

