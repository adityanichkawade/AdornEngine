#ifndef RENDERER_H
#define RENDERER_H

namespace Adorn{
    class ShaderProgram;
    class Primitive;
    
    class NodeAttribute {
    public:
        NodeAttribute();
        virtual ~NodeAttribute();

        void setShader(ShaderProgram *aShaderProgram);
        void setShape(Primitive *aShape);
        void render();
    private:
        ShaderProgram *_shaderProgram;
        Primitive *_shape;
    };
}
#endif /* RENDERER_H */

