//
// Created by Admin on 09.06.2024.
//

#include "MenuScene.h"
#include "../../GameController.h"
#include "../UI/ButtonCommands/ChangeSceneCommand.h"
#include "WeaponChoosingScene.h"
#include "GameScene.h"
#include "../../Systems/DrawableSystems/LabelDrawingSystem.h"
#include "../UI/ButtonCommands/QuitCommand.h"
#include "../../Systems/UpdatableSystems/InputHandlingSystem.h"
#include "../../Systems/UpdatableSystems/ButtonHandlingSystem.h"
#include "../../Systems/DrawableSystems/ButtonDrawingSystem.h"

void MenuScene::start() {



    auto window = GameController::getInstance()->window;

    auto& buttonHandler = GameController::getInstance()->buttonHandler;
    auto& labelHandler = GameController::getInstance()->labelHandler;

    buttonHandler.clear();
    labelHandler.clear();

    auto nameOfTheGameLabel = std::make_unique<UILabel>(sf::Vector2f(window->getSize().x/2, window->getSize().y/2 - 350), std::string("Magician Fest"), 72, sf::Color::Yellow);
    labelHandler.add(std::move(nameOfTheGameLabel));


    auto newGameButton = std::make_unique<UIButton>(sf::Vector2f(window->getSize().x/2, window->getSize().y/2 - 150), std::string("New game"), 24, sf::Vector2f(200, 100));
//    newGameButton->getDefaultSprite().setTextureRect(sf::IntRect(
//            0,
//            0,
//            96,
//            64));
//    newGameButton->getHoveredSprite().setTextureRect(sf::IntRect(
//            0,
//            64,
//            96,
//            64));

    newGameButton->setCommand(std::make_unique<ChangeSceneCommand>(std::make_unique<WeaponChoosingScene>()));
    buttonHandler.add(std::move(newGameButton));

    auto loadGameButton = std::make_unique<UIButton>(sf::Vector2f(window->getSize().x/2, window->getSize().y/2 ), std::string("Load game"), 24, sf::Vector2f(200, 100));
    loadGameButton->setCommand(std::make_unique<ChangeSceneCommand>(std::make_unique<GameScene>()));
    buttonHandler.add(std::move(loadGameButton));

    auto quitButton = std::make_unique<UIButton>(sf::Vector2f(window->getSize().x/2, window->getSize().y/2 + 150), std::string("Quit"), 24, sf::Vector2f(200, 100));
    quitButton->setCommand(std::make_unique<QuitCommand>());
    buttonHandler.add(std::move(quitButton));

    GameController::getInstance()->addUpdatableSystem(std::make_unique<ButtonHandlingSystem>());

    GameController::getInstance()->addDrawableSystem(std::make_unique<ButtonDrawingSystem>());
    GameController::getInstance()->addDrawableSystem(std::make_unique<LabelDrawingSystem>());
}
