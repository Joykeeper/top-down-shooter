#include "InputHandlingSystem.h"

#include "../../GameController.h"
#include "../../Utils.h"
#include "../../Model/Effects/MoveSpeedEffect.h"
#include "../../Model/Effects/AttackSpeedEffect.h"
#include <cmath>
#include <iostream>


void InputHandlingSystem::update(sf::Time deltaTime) const{
    //skills
    Player& player = GameController::getInstance()->player;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
        if (player.getEffects().size() < 1){
            player.addEffect(std::make_unique<MoveSpeedEffect>(1000, 4));
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)){
        if (player.getEffects().size() < 1){
            player.addEffect(std::make_unique<AttackSpeedEffect>(0.15, 3));
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
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) and GameController::getInstance()->player.hasWeapon()
        and playerWeapon->getTimeFromLastShot() >= playerWeapon->getShootingCooldown()){

        sf::Vector2f mousePos = GameController::getInstance()->getMousePos();

        sf::Vector2f projDir = Utils::normalizeVector(mousePos-playerWeapon->getPos()-sf::Vector2f(25, 25));

        GameController::getInstance()->projectileHandler.add(GameController::getInstance()->player.shoot(projDir).get());
    }

    player.move(Utils::normalizeVector(velocity)*player.getMoveSpeed()*deltaTime.asSeconds());


    //enemy spawning
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) and GameController::getInstance()->enemyHandler.getItems().empty()){
        auto enemy = new Enemy(sf::Vector2f(100,100));
        enemy->setWeapon(std::make_unique<Pistol>(enemy->getPos(), AllyOrEnemy::ENEMY));
        GameController::getInstance()->enemyHandler.add(enemy);
    }


}
