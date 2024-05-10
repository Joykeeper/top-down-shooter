//
// Created by Admin on 03.05.2024.
//

#include <iostream>
#include "ProjectileHandlingSystem.h"
#include "../../GameController.h"

auto moveProjectiles(std::vector<Magicball*> projectiles, sf::Time dt) -> void;
auto checkIfHit(std::vector<Magicball*> projectiles, sf::Time dt) -> void;
auto checkIfDead(std::vector<Magicball*> projectiles, sf::Time dt) -> void;


void ProjectileHandlingSystem::update(sf::Time dt) const {
    auto projectiles = GameController::getInstance()->projectileHandler.getItems();

    moveProjectiles(projectiles, dt);

    checkIfHit(projectiles, dt);

    checkIfDead(projectiles, dt);
}


auto moveProjectiles(std::vector<Magicball*> projectiles, sf::Time dt) -> void{
    for(auto& proj: projectiles){
        proj->move(proj->getDirection()*proj->getSpeed()*dt.asSeconds());
    }
}

auto checkIfHit(std::vector<Magicball*> projectiles, sf::Time dt) -> void{
    auto removedProjectiles = std::vector<Magicball*>();

    for(auto& proj: projectiles){
        if (proj->getAllyOrEnemy() == AllyOrEnemy::ALLY){
            auto enemies = GameController::getInstance()->enemyHandler.getItems();
            for(auto& enemy: enemies){
                if( enemy->getPos().x <= proj->getPos().x and proj->getPos().x <= enemy->getPos().x + 75 and
                        enemy->getPos().y <= proj->getPos().y and proj->getPos().y <= enemy->getPos().y + 75){
                        enemy->setHealth(enemy->getHealth()-proj->getDamage());
                        std::cout << enemy->getHealth() << "ehealth\n";
                        removedProjectiles.push_back(proj);
                        break;
                }
            }
        } else {
            auto player = &GameController::getInstance()->player;
            auto playerPos = player->getPos();
            if( playerPos.x <= proj->getPos().x and proj->getPos().x <= playerPos.x + 50 and
            playerPos.y <= proj->getPos().y and proj->getPos().y <= playerPos.y + 50){
                player->setHealth(player->getHealth()-proj->getDamage());
                removedProjectiles.push_back(proj);
            }
        }
    }

    for(auto& proj: removedProjectiles) {
        GameController::getInstance()->projectileHandler.remove(*proj);
    }
}

auto checkIfDead(std::vector<Magicball*> projectiles, sf::Time dt) -> void{
    auto removedProjectiles = std::vector<Magicball*>();

    projectiles = GameController::getInstance()->projectileHandler.getItems();

    for(auto& proj: projectiles){
        proj->setLifeTime(proj->getLifeTime()-dt.asSeconds());
        if(proj->getLifeTime() <= 0){
            removedProjectiles.push_back(proj);
        }
    }

    for(auto& proj: removedProjectiles) {
        GameController::getInstance()->projectileHandler.remove(*proj);
    }
}