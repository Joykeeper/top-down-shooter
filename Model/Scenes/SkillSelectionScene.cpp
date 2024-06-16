//
// Created by Admin on 15.06.2024.
//

#include "SkillSelectionScene.h"
#include "../Spells/Spell.h"
#include "../Effects/Effect.h"
#include "../../GameController.h"
#include "../../Systems/DrawableSystems/LabelDrawingSystem.h"
#include "../UI/ButtonCommands/SetNewActiveSkillCommand.h"
#include "../UI/ButtonCommands/SetNewPassiveSkillCommand.h"
#include "../../Systems/UpdatableSystems/ButtonHandlingSystem.h"
#include "../../Systems/DrawableSystems/ButtonDrawingSystem.h"

void SkillSelectionScene::start() {
    GameController::getInstance()->camera->setCenter(sf::Vector2f ( GameController::getInstance()->window->getSize().x/2,  GameController::getInstance()->window->getSize().y/2));

    GameController::getInstance()->window->setView(*GameController::getInstance()->camera);

    auto window = GameController::getInstance()->window;

    auto& buttonHandler = GameController::getInstance()->buttonHandler;
    auto& labelHandler = GameController::getInstance()->labelHandler;

    buttonHandler.clear();
    labelHandler.clear();

    auto chooseSkillLabel = std::make_unique<UILabel>(sf::Vector2f (window->getSize().x/2, window->getSize().y/2 - 100), std::string ("Choose new skill"), 50, sf::Color::Magenta);
    labelHandler.add(std::move(chooseSkillLabel));

    std::unique_ptr<UIButton> skill1 = nullptr;
    std::unique_ptr<UIButton> skill2 = nullptr;
    std::unique_ptr<UIButton> skill3 = nullptr;

    for (auto& skill: activeSkills){
        if (!skill1){

             skill1 = std::make_unique<UIButton>(sf::Vector2f(window->getSize().x/2 - 300, window->getSize().y/2 + 100), std::string(skill->getName()), 32, sf::Vector2f(200, 200), sf::Color::Black, sf::Color::Green, sf::Color::White);

            skill1->setCommand(std::make_unique<SetNewActiveSkillCommand>(&skill));

        } else if(!skill2){

            skill2 = std::make_unique<UIButton>(sf::Vector2f(window->getSize().x/2, window->getSize().y/2 + 100), std::string(skill->getName()), 32, sf::Vector2f(200, 200), sf::Color::Black, sf::Color::Green, sf::Color::White);
            skill2->setCommand(std::make_unique<SetNewActiveSkillCommand>(&skill));

        } else if(!skill3){

            skill3 = std::make_unique<UIButton>(sf::Vector2f(window->getSize().x/2 + 300, window->getSize().y/2 + 100), std::string(skill->getName()), 32, sf::Vector2f(200, 200), sf::Color::Black, sf::Color::Green, sf::Color::White);
            skill3->setCommand(std::make_unique<SetNewActiveSkillCommand>(&skill));

        }
    }

    for (auto& skill: passiveSkills){
        if (!skill1){

            skill1 = std::make_unique<UIButton>(sf::Vector2f(window->getSize().x/2 - 300, window->getSize().y/2 + 100), std::string(skill->getName()), 32, sf::Vector2f(200, 200), sf::Color::Black, sf::Color::Cyan, sf::Color::White);
            skill1->setCommand(std::make_unique<SetNewPassiveSkillCommand>(&skill));

        } else if(!skill2){

            skill2 = std::make_unique<UIButton>(sf::Vector2f(window->getSize().x/2, window->getSize().y/2 + 100), std::string(skill->getName()), 32, sf::Vector2f(200, 200), sf::Color::Black, sf::Color::Cyan, sf::Color::White);
            skill2->setCommand(std::make_unique<SetNewPassiveSkillCommand>(&skill));

        } else if(!skill3){

            skill3 = std::make_unique<UIButton>(sf::Vector2f(window->getSize().x/2 + 300, window->getSize().y/2 + 100), std::string(skill->getName()), 32, sf::Vector2f(200, 200), sf::Color::Black, sf::Color::Cyan, sf::Color::White);
            skill3->setCommand(std::make_unique<SetNewPassiveSkillCommand>(&skill));

        }
    }

    buttonHandler.add(std::move(skill1));
    buttonHandler.add(std::move(skill2));
    buttonHandler.add(std::move(skill3));

    GameController::getInstance()->addUpdatableSystem(std::make_unique<ButtonHandlingSystem>());
    GameController::getInstance()->addDrawableSystem(std::make_unique<ButtonDrawingSystem>());
    GameController::getInstance()->addDrawableSystem(std::make_unique<LabelDrawingSystem>());
}
