/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Scene.h
 * Author: Aditya
 *
 * Created on September 23, 2016, 10:17 PM
 */

#ifndef SCENE_H
#define SCENE_H

#include <vector>

namespace Adorn{
    class Group;
    class Node;

    class Scene {
    public:
        Scene();
        virtual ~Scene();

        void addNode(Node *aNode);
        void render();
        void setClearColor(float aClearColor[]);
    private:
        Group *_group;
        float _clearColor[4];
    };
}
#endif /* SCENE_H */

