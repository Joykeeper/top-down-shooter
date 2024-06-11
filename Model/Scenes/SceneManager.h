#pragma once


#include "Scene.h"
#include "MenuScene.h"
#include <memory>

class SceneManager {
    std::unique_ptr<Scene> currentScene;
public:
    SceneManager(){};
    void changeScene(std::unique_ptr<Scene>);
};

