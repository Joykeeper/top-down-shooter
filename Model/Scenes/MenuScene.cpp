//
// Created by Admin on 09.06.2024.
//

#include "MenuScene.h"
#include "../../GameController.h"
#include "../UI/ButtonCommands/ChangeSceneCommand.h"
#include "WeaponChoosingScene.h"
#include "GameScene.h"

void MenuScene::start() {
    auto& buttonHandler = GameController::getInstance()->buttonHandler;

    buttonHandler.clear();

    auto newGameButton = std::make_unique<UIButton>(sf::Vector2f(400, 200), std::string("New game"), 16, sf::Vector2f(100, 100));
    newGameButton->setCommand(std::make_unique<ChangeSceneCommand>(std::make_unique<WeaponChoosingScene>()));
    buttonHandler.add(std::move(newGameButton));

    auto loadGameButton = std::make_unique<UIButton>(sf::Vector2f(400, 310), std::string("Load game"), 16, sf::Vector2f(100, 100));
    loadGameButton->setCommand(std::make_unique<ChangeSceneCommand>(std::make_unique<GameScene>()));
    buttonHandler.add(std::move(loadGameButton));

    auto quitButton = std::make_unique<UIButton>(sf::Vector2f(400, 420), std::string("Quit"), 16, sf::Vector2f(100, 100));
    quitButton->setCommand(std::make_unique<QuitCommand>());
    buttonHandler.add(std::move(quitButton));

    GameController::getInstance()->addUpdatableSystem(new ButtonHandlingSystem());
    GameController::getInstance()->addDrawableSystem(new ButtonDrawingSystem());
    GameController::getInstance()->addUpdatableSystem(new InputHandlingSystem());
}
