//
// Created by Admin on 09.06.2024.
//

#include "WeaponChoosingScene.h"
#include "../../GameController.h"
#include "../UI/ButtonCommands/ChangeSceneCommand.h"
#include "GameScene.h"

void WeaponChoosingScene::start() {
    auto& buttonHandler = GameController::getInstance()->buttonHandler;

    buttonHandler.clear();

    auto fireStaff = std::make_unique<UIButton>(sf::Vector2f(250, 200), std::string("Fire staff"), 16, sf::Vector2f(100, 100));
    fireStaff->setCommand(std::make_unique<ChangeSceneCommand>(std::make_unique<GameScene>()));
    buttonHandler.add(std::move(fireStaff));

    auto waterStaff = std::make_unique<UIButton>(sf::Vector2f(500, 200), std::string("Water staff"), 15, sf::Vector2f(100, 100));
    waterStaff->setCommand(std::make_unique<ChangeSceneCommand>(std::make_unique<GameScene>()));
    buttonHandler.add(std::move(waterStaff));

    GameController::getInstance()->addUpdatableSystem(new ButtonHandlingSystem());
    GameController::getInstance()->addDrawableSystem(new ButtonDrawingSystem());
}
