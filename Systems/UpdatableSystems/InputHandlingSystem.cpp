#include "InputHandlingSystem.h"

#include "../../GameController.h"
#include "../../Utils.h"
#include "../../Model/Effects/MoveSpeedEffect.h"
#include "../../Model/Effects/AttackSpeedEffect.h"
#include "../../Model/Scenes/GameMenuScene.h"
#include "../../Model/Scenes/GameScene.h"
#include "../../Model/Scenes/GameOverScene.h"
#include "../../Model/Scenes/SkillSelectionScene.h"
#include <cmath>
#include <iostream>


void InputHandlingSystem::update(sf::Time deltaTime) const{

    Player& player = GameController::getInstance()->player;

    if (player.getHealth() <= 0){
        GameController::getInstance()->sceneManager.changeScene(std::make_unique<GameOverScene>());
    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
        if (player.getActiveSkill1() && player.getActiveSkill1()->getTimeTillNext() <= 0){
            player.getActiveSkill1()->cast(GameController::getInstance()->getMousePos());
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)){
        if (player.getActiveSkill2() && player.getActiveSkill2()->getTimeTillNext() <= 0){
            player.getActiveSkill2()->cast(GameController::getInstance()->getMousePos());
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)){
        if (GameController::getInstance()->unusedSkillPoints != 0){
            auto activeSkillCount = Utils::generateNumberInRange(0, 4);
            GameController::getInstance()->sceneManager.changeScene(std::make_unique<SkillSelectionScene>(Weapon::generateActiveSkills(activeSkillCount, player.getWeaponType()), Weapon::generatePassiveSkills(3-activeSkillCount, player.getWeaponType())));
            GameController::getInstance()->unusedSkillPoints--;
        }
    }

    //movement
    sf::Vector2f velocity = {};

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        velocity += sf::Vector2f (0, -1);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        velocity += sf::Vector2f (-1, 0);

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        velocity += sf::Vector2f (0, 1);

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        velocity += sf::Vector2f (1, 0);
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && GameController::getInstance()->player.getDefaultAttack()){

        sf::Vector2f mousePos = GameController::getInstance()->getMousePos();

        sf::Vector2f projDir = Utils::normalizeVector(mousePos-player.getPos());

        if (player.getDefaultAttack()->getTimeTillNext() <= 0) player.getDefaultAttack()->cast(projDir);

    }
    player.getDefaultAttack()->updateTimeTillNext(deltaTime.asSeconds());

    if (velocity.x == 0 and velocity.y == 0){
        player.getAnimationHandler().setAnimation("stop");
    } else{
        player.getAnimationHandler().setAnimation("idle");
    }

    player.move(Utils::normalizeVector(velocity)*player.getMoveSpeed()*deltaTime.asSeconds());

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        GameController::getInstance()->sceneManager.changeScene(std::make_unique<GameOverScene>());
    }


}
