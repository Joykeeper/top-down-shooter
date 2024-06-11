//
// Created by Admin on 09.06.2024.
//

#include "SceneManager.h"
#include "../../GameController.h"

void SceneManager::changeScene(std::unique_ptr<Scene> scene) {
    GameController::getInstance()->updatableSystems.clear();
    GameController::getInstance()->drawableSystems.clear();

    currentScene = std::move(scene);

    currentScene->start();
}
