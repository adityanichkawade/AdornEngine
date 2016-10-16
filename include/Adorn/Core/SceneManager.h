/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SceneManager.h
 * Author: Aditya
 *
 * Created on September 25, 2016, 4:41 PM
 */

#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <vector>

namespace Adorn{
    class Scene;
    
    class SceneManager {
    public:
        SceneManager();
        virtual ~SceneManager();
        
        void renderScene();
    private:
        std::vector<Scene*> _scene;
    };
}
#endif /* SCENEMANAGER_H */

