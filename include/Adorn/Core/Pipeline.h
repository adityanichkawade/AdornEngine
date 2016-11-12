#ifndef PIPELINE_H
#define PIPELINE_H

namespace Adorn{
    class ShaderProgram;
    class Buffer;
    
    class Pipeline {
    public:
        Pipeline();
        virtual ~Pipeline();

        void setShader(ShaderProgram *aShaderProgram);
		void setBuffer(Buffer *aBuffer);
        void render();
    private:
        ShaderProgram *_shaderProgram;
        Buffer *_buffer;
    };
}
#endif /* PIPELINE_H */

