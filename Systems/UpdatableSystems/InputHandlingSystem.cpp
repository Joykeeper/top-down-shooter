#include "InputHandlingSystem.h"

#include "../../GameController.h"
#include "../../Utils.h"
#include <cmath>
#include <iostream>


void InputHandlingSystem::update(sf::Time deltaTime) const{
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

    auto playerWeapon = GameController::getInstance()->player.getWeapon();
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) and GameController::getInstance()->player.hasWeapon()
        and playerWeapon->getTimeFromLastShot() >= playerWeapon->getShootingCooldown()){

        sf::Vector2f mousePos = GameController::getInstance()->getMousePos();

        sf::Vector2f projDir = Utils::normalizeVector(mousePos-playerWeapon->getPos()-sf::Vector2f(25, 25));

        GameController::getInstance()->projectileHandler.add(*GameController::getInstance()->player.shoot(projDir));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) and GameController::getInstance()->enemyHandler.getItems().empty()){
        auto* enemy = new Enemy(sf::Vector2f(100,100));
        enemy->setWeapon(*new Pistol(enemy->getPos(), AllyOrEnemy::ENEMY));
        GameController::getInstance()->enemyHandler.add(*enemy);
    }

    Player& player = GameController::getInstance()->player;


    player.move(Utils::normalizeVector(velocity)*player.getMoveSpeed()*deltaTime.asSeconds());

}
