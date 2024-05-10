//
// Created by Admin on 03.05.2024.
//

#include <iostream>
#include "EnemyHandlingSystem.h"
#include "../../GameController.h"
#include "../../Utils.h"
#include "cmath"

auto checkHealth(auto enemies) -> void;
auto shootAtPlayer(auto enemies) -> void;
auto checkIfPlayerInRadius(auto enemies) -> void;
auto moveEnemies(auto, sf::Time) -> void;

void EnemyHandlingSystem::update(sf::Time dt) const {
    auto enemies = GameController::getInstance()->enemyHandler.getItems();

    checkHealth(enemies);

    checkIfPlayerInRadius(enemies);

    shootAtPlayer(enemies);

    moveEnemies(enemies, dt);


}

void moveEnemies(auto enemies, sf::Time dt){
    sf::Vector2f playerPos = GameController::getInstance()->player.getPos();
    sf::Vector2f velocity;
    for(auto& enemy: enemies){
        if (!enemy->isPlayerInRadius()){
            velocity = Utils::normalizeVector(playerPos-enemy->getPos());

            enemy->move(velocity*enemy->getMoveSpeed()*dt.asSeconds());
        }
    }
}

void checkHealth(auto enemies){
    auto removedEnemies = std::vector<Enemy*>();

    auto player = GameController::getInstance()->player;


    for(auto& enemy: enemies){
        if(enemy->getHealth() <= 0){
            removedEnemies.push_back(enemy);
        }
    }

    for(auto& enemy: removedEnemies) {
        GameController::getInstance()->enemyHandler.remove(*enemy);
    }
}

void shootAtPlayer(auto enemies){
    auto playerPos = GameController::getInstance()->player.getPos();
    for(auto& enemy: enemies){
        if (enemy->hasWeapon() and enemy->isPlayerInRadius()) {
            if (enemy->getWeapon()->getTimeFromLastShot() >= enemy->getWeapon()->getShootingCooldown()) {
                sf::Vector2f projDir = Utils::normalizeVector(playerPos - enemy->getPos() - sf::Vector2f(25, 25));

                GameController::getInstance()->projectileHandler.add(*enemy->shoot(projDir));
            }
        }
    }
}

void checkIfPlayerInRadius(auto enemies){
    auto playerPos = GameController::getInstance()->player.getPos();
    for (auto& enemy: enemies){
        std::cout << sqrt((playerPos.x - enemy->getPos().x)*(playerPos.x - enemy->getPos().x) +
                          (playerPos.y - enemy->getPos().y)*(playerPos.y - enemy->getPos().y)) << "sqrt\n";
        std::cout << enemy->getShootingRadius();
        std::cout << " here\n";
        if (sqrt((playerPos.x - enemy->getPos().x)*(playerPos.x - enemy->getPos().x) +
            (playerPos.y - enemy->getPos().y)*(playerPos.y - enemy->getPos().y)) <= enemy->getShootingRadius()){
                enemy->setPlayerInRadius(true);


        } else{
                enemy->setPlayerInRadius(false);
        }
    }
}