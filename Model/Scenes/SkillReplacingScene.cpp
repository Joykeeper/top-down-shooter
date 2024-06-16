//
// Created by Admin on 15.06.2024.
//

#include "SkillReplacingScene.h"
#include "../../GameController.h"
#include "../UI/ButtonCommands/ReplaceSkillCommand.h"
#include "../../Systems/DrawableSystems/LabelDrawingSystem.h"
#include "../../Systems/UpdatableSystems/ButtonHandlingSystem.h"
#include "../../Systems/DrawableSystems/ButtonDrawingSystem.h"

void SkillReplacingScene::start() {

    auto window = GameController::getInstance()->window;

    auto& buttonHandler = GameController::getInstance()->buttonHandler;
    auto& labelHandler = GameController::getInstance()->labelHandler;

    buttonHandler.clear();
    labelHandler.clear();

    auto chooseSkillToReplaceLabel = std::make_unique<UILabel>(sf::Vector2f (window->getSize().x/2, window->getSize().y/2 + 50), std::string ("Choose skill to replace"), 50, sf::Color::Magenta);
    labelHandler.add(std::move(chooseSkillToReplaceLabel));

    auto& player = GameController::getInstance()->player;

    if (activeSkillToSet) {
        auto skill1 = std::make_unique<UIButton>(sf::Vector2f(window->getSize().x/2 - 300, window->getSize().y/2 - 120), std::string(player.getActiveSkill1()->getName()), 32, sf::Vector2f(200, 200));
        skill1->setCommand(std::make_unique<ReplaceSkillCommand>(1, activeSkillToSet));

        auto skill2 = std::make_unique<UIButton>(sf::Vector2f(window->getSize().x/2 + 300, window->getSize().y/2 - 120), std::string(player.getActiveSkill2()->getName()), 32, sf::Vector2f(200, 200));
        skill2->setCommand(std::make_unique<ReplaceSkillCommand>(1, activeSkillToSet));

        buttonHandler.add(std::move(skill1));
        buttonHandler.add(std::move(skill2));

    } else if (passiveSkillToSet) {

        auto skill1 = std::make_unique<UIButton>(sf::Vector2f(window->getSize().x/2 - 300, window->getSize().y/2 - 120), std::string(player.getPassiveSkill1()->getName()), 32, sf::Vector2f(200, 200));
        skill1 ->setCommand(std::make_unique<ReplaceSkillCommand>(1,nullptr, passiveSkillToSet));

        auto skill2 = std::make_unique<UIButton>(sf::Vector2f(window->getSize().x/2 + 300, window->getSize().y/2 - 120), std::string(player.getPassiveSkill2()->getName()), 32, sf::Vector2f(200, 200));
        skill2 ->setCommand(std::make_unique<ReplaceSkillCommand>(1,nullptr, passiveSkillToSet));

        buttonHandler.add(std::move(skill1));
        buttonHandler.add(std::move(skill2));
    }

    GameController::getInstance()->addUpdatableSystem(std::make_unique<ButtonHandlingSystem>());
    GameController::getInstance()->addDrawableSystem(std::make_unique<ButtonDrawingSystem>());
    GameController::getInstance()->addDrawableSystem(std::make_unique<LabelDrawingSystem>());

}
