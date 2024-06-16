//
// Created by Admin on 09.06.2024.
//

#include "WeaponChoosingScene.h"
#include "../../GameController.h"
#include "../UI/ButtonCommands/ChangeSceneCommand.h"
#include "GameScene.h"
#include "../../Systems/DrawableSystems/LabelDrawingSystem.h"
#include "../../Systems/UpdatableSystems/ButtonHandlingSystem.h"
#include "../../Systems/DrawableSystems/ButtonDrawingSystem.h"
#include "../UI/ButtonCommands/ChoosePlayerWeaponCommand.h"

void WeaponChoosingScene::start() {

    auto window = GameController::getInstance()->window;

    auto& buttonHandler = GameController::getInstance()->buttonHandler;
    auto& labelHandler = GameController::getInstance()->labelHandler;

    GameController::getInstance()->resetGame();

    auto chooseWeaponLabel = std::make_unique<UILabel>(sf::Vector2f (window->getSize().x/2, window->getSize().y/2 - 200), std::string ("Choose your weapon"), 50, sf::Color::Magenta);
    labelHandler.add(std::move(chooseWeaponLabel));

    auto fireStaff = std::make_unique<UIButton>(sf::Vector2f(window->getSize().x/2 - 200, window->getSize().y/2 + 50), std::string("Fire staff"), 24, sf::Vector2f(150, 150));
    fireStaff->setCommand(std::make_unique<ChoosePlayerWeaponCommand>(WeaponType::FIRE_STAFF));
    buttonHandler.add(std::move(fireStaff));

    auto waterStaff = std::make_unique<UIButton>(sf::Vector2f(window->getSize().x/2 + 200, window->getSize().y/2 + 50), std::string("Water staff"), 24, sf::Vector2f(150, 150));
    waterStaff->setCommand(std::make_unique<ChoosePlayerWeaponCommand>(WeaponType::WATER_STAFF));
    buttonHandler.add(std::move(waterStaff));

    GameController::getInstance()->addUpdatableSystem(std::make_unique<ButtonHandlingSystem>());

    GameController::getInstance()->addDrawableSystem(std::make_unique<ButtonDrawingSystem>());
    GameController::getInstance()->addDrawableSystem(std::make_unique<LabelDrawingSystem>());
}
