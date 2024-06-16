//
// Created by Admin on 15.06.2024.
//

#include "GameOverScene.h"
#include "../../Systems/UpdatableSystems/ButtonHandlingSystem.h"
#include "../../Systems/DrawableSystems/ButtonDrawingSystem.h"
#include "../../GameController.h"
#include "../UI/ButtonCommands/ChangeSceneCommand.h"
#include "WeaponChoosingScene.h"
#include "../../Systems/DrawableSystems/LabelDrawingSystem.h"
#include "../UI/ButtonCommands/QuitCommand.h"

void GameOverScene::start() {
    GameController::getInstance()->camera->setCenter(sf::Vector2f ( GameController::getInstance()->window->getSize().x/2,  GameController::getInstance()->window->getSize().y/2));

    GameController::getInstance()->window->setView(*GameController::getInstance()->camera);

    auto window = GameController::getInstance()->window;

    auto& buttonHandler = GameController::getInstance()->buttonHandler;
    auto& labelHandler = GameController::getInstance()->labelHandler;

    buttonHandler.clear();
    labelHandler.clear();

    auto mainMenuButton = std::make_unique<UIButton>(sf::Vector2f(window->getSize().x/2 - 300, window->getSize().y/2), std::string("Main Menu"), 24, sf::Vector2f(200, 100));
    mainMenuButton->setCommand(std::make_unique<ChangeSceneCommand>(std::make_unique<MenuScene>()));
    buttonHandler.add(std::move(mainMenuButton));

    auto retryGameButton = std::make_unique<UIButton>(sf::Vector2f(window->getSize().x/2, window->getSize().y/2), std::string("Retry"), 24, sf::Vector2f(200, 100));
    retryGameButton->setCommand(std::make_unique<ChangeSceneCommand>(std::make_unique<WeaponChoosingScene>()));
    buttonHandler.add(std::move(retryGameButton));


    auto quitButton = std::make_unique<UIButton>(sf::Vector2f(window->getSize().x/2 + 300, window->getSize().y/2), std::string("Quit"), 24, sf::Vector2f(200, 100));
    quitButton->setCommand(std::make_unique<QuitCommand>());
    buttonHandler.add(std::move(quitButton));

    auto gameOverLabel = std::make_unique<UILabel>(sf::Vector2f(window->getSize().x/2, window->getSize().y/2 - 300), "Game over", 100, sf::Color::Red);
    labelHandler.add(std::move(gameOverLabel));

    auto betterLuckLabel = std::make_unique<UILabel>(sf::Vector2f(window->getSize().x/2, window->getSize().y/2 - 200),
                                                     "Better luck next time", 32, sf::Color::Blue);
    labelHandler.add(std::move(betterLuckLabel));


    GameController::getInstance()->addUpdatableSystem(std::make_unique<ButtonHandlingSystem>());
    GameController::getInstance()->addDrawableSystem(std::make_unique<ButtonDrawingSystem>());
    GameController::getInstance()->addDrawableSystem(std::make_unique<LabelDrawingSystem>());
}
