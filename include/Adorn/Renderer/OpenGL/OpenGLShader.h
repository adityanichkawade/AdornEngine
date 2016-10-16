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

#ifndef OPENGL_SHADER_H
#define OPENGL_SHADER_H

#include <Adorn/Renderer/Shader.h>

namespace Adorn {
	class OpenGLShader : public Shader{
	public:
		OpenGLShader();
		OpenGLShader(ShaderType aType);
		~OpenGLShader();

		void setShaderSource(const char* aShaderSource);
		unsigned int getShaderId() const;
		bool compile();

	protected:
		void createShader();
	private:
		unsigned int _shaderId;
	};
}

#endif /* OPENGL_SHADER_H */

