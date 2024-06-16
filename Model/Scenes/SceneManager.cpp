//
// Created by Admin on 09.06.2024.
//

#include "SceneManager.h"
#include "../../GameController.h"

void SceneManager::changeScene(std::unique_ptr<Scene> scene) {
    sceneToSet = std::move(scene);
}

void SceneManager::setNewScene() {
    if (sceneToSet){
        currentScene = std::move(sceneToSet);

        GameController::getInstance()->updatableSystems.clear();
        GameController::getInstance()->drawableSystems.clear();

        sceneToSet = nullptr;
        currentScene->start();
    }
}
