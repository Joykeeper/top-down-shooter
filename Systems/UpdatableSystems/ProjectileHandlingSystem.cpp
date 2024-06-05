//
// Created by Admin on 03.05.2024.
//

#include <iostream>
#include "ProjectileHandlingSystem.h"
#include "../../GameController.h"
#include "../../Utils.h"
#include "../../Model/Effects/AttackSpeedEffect.h"

auto moveProjectiles(std::vector<std::unique_ptr<Magicball>>& projectiles, sf::Time dt) -> void;
auto checkIfHit(std::vector<std::unique_ptr<Magicball>>& projectiles, sf::Time dt) -> void;
auto checkIfDead(std::vector<std::unique_ptr<Magicball>>& projectiles, sf::Time dt) -> void;


void ProjectileHandlingSystem::update(sf::Time dt) const {
    auto& projectiles = GameController::getInstance()->projectileHandler.getItems();

    moveProjectiles(GameController::getInstance()->projectileHandler.getItems(), dt);

    checkIfHit(GameController::getInstance()->projectileHandler.getItems(), dt);

    checkIfDead(GameController::getInstance()->projectileHandler.getItems(), dt);
}


auto moveProjectiles(std::vector<std::unique_ptr<Magicball>>& projectiles, sf::Time dt) -> void{
    for(auto& proj: projectiles){
        proj->move(proj->getDirection()*proj->getSpeed()*dt.asSeconds());
    }
}

auto checkIfHit(std::vector<std::unique_ptr<Magicball>>& projectiles, sf::Time dt) -> void{
    auto removedProjectiles = std::vector<Magicball*>();

    for(auto& proj: projectiles){
        if (proj->getAllyOrEnemy() == AllyOrEnemy::ALLY){
            auto enemies = &GameController::getInstance()->enemyHandler.getItems();
            for(auto& enemy: *enemies){
                if(Utils::objectsCollide(*proj, *enemy)){
                        for (auto& f: proj->getEffects()){
                            enemy->addEffect(std::move(f));
                        }
                        enemy->setHealth(enemy->getHealth()-proj->getDamage());
                        removedProjectiles.push_back(proj.get());
                        break;
                }
            }
        } else {
            auto player = &GameController::getInstance()->player;
            if( Utils::objectsCollide(*proj, *player)){

                for (auto& f: proj->getEffects()){
                    player->addEffect(std::move(f));
                }

                player->setHealth(player->getHealth()-proj->getDamage());
                removedProjectiles.push_back(proj.get());
            }
        }
    }

    for(auto proj: removedProjectiles) {
        GameController::getInstance()->projectileHandler.remove(proj);
    }

    removedProjectiles.clear();
}

auto checkIfDead(std::vector<std::unique_ptr<Magicball>>& projectiles, sf::Time dt) -> void{
    auto removedProjectiles = std::vector<Magicball*>();

    for(auto& proj: projectiles){
        proj->setLifeTime(proj->getLifeTime()-dt.asSeconds());
        if(proj->getLifeTime() <= 0){
            removedProjectiles.push_back(proj.get());
        }
    }

    for(auto proj: removedProjectiles) {
        GameController::getInstance()->projectileHandler.remove(proj);
    }

    removedProjectiles.clear();
}