#ifndef OPENGL_SHADER_PROGRAM_H
#define OPENGL_SHADER_PROGRAM_H

#include <Adorn/Renderer/ShaderProgram.h>

namespace Adorn {

	class Shader;

	class OpenGLShaderProgram : public ShaderProgram {
	public:
		OpenGLShaderProgram();
		~OpenGLShaderProgram();

		bool attach(Shader *aShader);
		void render();
	
	private:
		void useProgram();
		void linkProgram();
		void createShaderProgram();
	
	private:
		unsigned int _shaderProgram;
	};
};


#endif // !OPENGL_SHADER_PROGRAM_H
