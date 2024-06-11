#include "InputHandlingSystem.h"

#include "../../GameController.h"
#include "../../Utils.h"
#include "../../Model/Effects/MoveSpeedEffect.h"
#include "../../Model/Effects/AttackSpeedEffect.h"
#include "../../Model/Scenes/GameMenuScene.h"
#include "../../Model/Scenes/GameScene.h"
#include <cmath>
#include <iostream>


void InputHandlingSystem::update(sf::Time deltaTime) const{
    //skills
    Player& player = GameController::getInstance()->player;

    if (player.getActiveSkill1()) player.getActiveSkill1()->updateTimeTillNext(deltaTime.asSeconds());
    if (player.getActiveSkill2()) player.getActiveSkill2()->updateTimeTillNext(deltaTime.asSeconds());



    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)){
        if (player.getActiveSkill1() && player.getActiveSkill1()->getTimeTillNext() <= 0){
            player.getActiveSkill1()->cast(GameController::getInstance()->getMousePos());
            //player.addEffect(std::make_unique<MoveSpeedEffect>(1000, 4));
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)){
        if (player.getActiveSkill2() && player.getActiveSkill2()->getTimeTillNext() <= 0){
            player.getActiveSkill2()->cast(GameController::getInstance()->getMousePos());
            //player.addEffect(std::make_unique<MoveSpeedEffect>(1000, 4));
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
        if (player.getEffects().empty()){
            player.addEffect(std::make_unique<MoveSpeedEffect>(1000, 4));
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)){
        if (player.getEffects().empty()){
            player.addEffect(std::make_unique<AttackSpeedEffect>(0.2, 3));
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)){
        if (GameController::getInstance()->auraHandler.getItems().empty()){
            GameController::getInstance()->auraHandler.add(std::make_unique<BurningAura>(
                    GameController::getInstance()->getMousePos(),
                                                  150, 3, 1, nullptr,
                                                  AllyOrEnemy::ALLY, 2));

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

    auto playerWeapon = &GameController::getInstance()->player.getWeapon();
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && GameController::getInstance()->player.hasWeapon()
        and playerWeapon->getTimeFromLastShot() >= playerWeapon->getShootingCooldown()){

        sf::Vector2f mousePos = GameController::getInstance()->getMousePos();

        sf::Vector2f projDir = Utils::normalizeVector(mousePos-playerWeapon->getPos()-sf::Vector2f(25, 25));

        GameController::getInstance()->projectileHandler.add(GameController::getInstance()->player.shoot(projDir));
    }

    player.move(Utils::normalizeVector(velocity)*player.getMoveSpeed()*deltaTime.asSeconds());


    //enemy spawning
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && GameController::getInstance()->enemyHandler.getItems().empty()){
        auto enemy = std::make_unique<PistolEnemy>(sf::Vector2f(100,100));
        GameController::getInstance()->enemyHandler.add(std::move(enemy));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        GameController::getInstance()->sceneManager.changeScene(std::make_unique<GameMenuScene>());
    }


}
