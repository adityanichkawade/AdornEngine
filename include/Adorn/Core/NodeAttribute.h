/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Renderer.h
 * Author: Aditya
 *
 * Created on September 23, 2016, 10:18 PM
 */

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

