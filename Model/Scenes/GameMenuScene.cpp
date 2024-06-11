//
// Created by Admin on 11.06.2024.
//

#include "GameMenuScene.h"
#include "../UI/UIButton.h"
#include "../../GameController.h"
#include "GameScene.h"
#include "../UI/ButtonCommands/ChangeSceneCommand.h"

void GameMenuScene::start() {
    auto& buttonHandler = GameController::getInstance()->buttonHandler;

    buttonHandler.clear();

    auto resumeGameButton = std::make_unique<UIButton>(sf::Vector2f(400, 200), std::string("Resume"), 16, sf::Vector2f(100, 100));
    resumeGameButton->setCommand(std::make_unique<ChangeSceneCommand>(std::make_unique<GameScene>()));
    buttonHandler.add(std::move(resumeGameButton));

    auto saveGameButton = std::make_unique<UIButton>(sf::Vector2f(400, 310), std::string("Save game"), 16, sf::Vector2f(100, 100));
    buttonHandler.add(std::move(saveGameButton));

    auto quitButton = std::make_unique<UIButton>(sf::Vector2f(400, 420), std::string("Quit"), 16, sf::Vector2f(100, 100));
    quitButton->setCommand(std::make_unique<QuitCommand>());
    buttonHandler.add(std::move(quitButton));

    GameController::getInstance()->addUpdatableSystem(new ButtonHandlingSystem());
    GameController::getInstance()->addDrawableSystem(new ButtonDrawingSystem());

}
