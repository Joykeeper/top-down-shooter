//
// Created by Admin on 09.06.2024.
//

#include "ChangeSceneCommand.h"
#include "../../../GameController.h"

void ChangeSceneCommand::fire() {
    auto& sceneManager = GameController::getInstance()->sceneManager;
    sceneManager.changeScene(std::move(newScene));
}
