/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Shader.h
 * Author: Aditya
 *
 * Created on September 23, 2016, 10:16 PM
 */

#ifndef SHADER_H
#define SHADER_H

namespace Adorn {
    class Shader {
    public:
        enum ShaderType {
            VERTEX,
            PIXEL
        };
        
        virtual ~Shader();
        virtual void setShaderSource(const char* aShaderSource) = 0;

		void setShaderType(ShaderType aShaderType);
    protected:
		Shader();
		Shader(ShaderType aShaderType);
		
		virtual void createShader() = 0;
        virtual bool compile() = 0;
	
	protected:
		ShaderType _shaderType;
		char *_shaderSource;
    };
}

#endif /* SHADER_H */

