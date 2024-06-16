//
// Created by Admin on 16.06.2024.
//

#include "ChoosePlayerWeaponCommand.h"
#include "../../../GameController.h"
#include "../../Scenes/GameScene.h"

void ChoosePlayerWeaponCommand::fire() {
    auto& player = GameController::getInstance()->player;
    player.setWeaponType(weaponType);

    auto& sceneManager = GameController::getInstance()->sceneManager;
    sceneManager.changeScene(std::make_unique<GameScene>());
}
