//
// Created by Admin on 11.06.2024.
//

#include "GameMenuScene.h"
#include "../UI/UIButton.h"
#include "../../GameController.h"
#include "GameScene.h"
#include "../UI/ButtonCommands/ChangeSceneCommand.h"
#include "../../Systems/DrawableSystems/LabelDrawingSystem.h"
#include "../UI/ButtonCommands/QuitCommand.h"
#include "../../Systems/UpdatableSystems/ButtonHandlingSystem.h"
#include "../../Systems/DrawableSystems/ButtonDrawingSystem.h"

void GameMenuScene::start() {

    GameController::getInstance()->camera->setCenter(sf::Vector2f ( GameController::getInstance()->window->getSize().x/2,  GameController::getInstance()->window->getSize().y/2));

    GameController::getInstance()->window->setView(*GameController::getInstance()->camera);

    auto window = GameController::getInstance()->window;

    auto& buttonHandler = GameController::getInstance()->buttonHandler;
    auto& labelHandler = GameController::getInstance()->labelHandler;

    buttonHandler.clear();
    labelHandler.clear();

    auto pausedLabel = std::make_unique<UILabel>(sf::Vector2f(window->getSize().x/2, window->getSize().y/2 - 350), std::string("Paused"), 32, sf::Color::Yellow);
    labelHandler.add(std::move(pausedLabel));

    auto resumeGameButton = std::make_unique<UIButton>(sf::Vector2f(window->getSize().x/2, window->getSize().y/2 - 150), std::string("Resume"), 16, sf::Vector2f(100, 100));
    resumeGameButton->setCommand(std::make_unique<ChangeSceneCommand>(std::make_unique<GameScene>()));
    buttonHandler.add(std::move(resumeGameButton));

    auto saveGameButton = std::make_unique<UIButton>(sf::Vector2f(window->getSize().x/2, window->getSize().y/2 + 0), std::string("Save game"), 16, sf::Vector2f(100, 100));
    buttonHandler.add(std::move(saveGameButton));

    auto quitButton = std::make_unique<UIButton>(sf::Vector2f(window->getSize().x/2, window->getSize().y/2 + 150), std::string("Quit"), 16, sf::Vector2f(100, 100));
    quitButton->setCommand(std::make_unique<QuitCommand>());
    buttonHandler.add(std::move(quitButton));

    GameController::getInstance()->addUpdatableSystem(std::make_unique<ButtonHandlingSystem>());
    GameController::getInstance()->addDrawableSystem(std::make_unique<ButtonDrawingSystem>());
    GameController::getInstance()->addDrawableSystem(std::make_unique<LabelDrawingSystem>());

}
