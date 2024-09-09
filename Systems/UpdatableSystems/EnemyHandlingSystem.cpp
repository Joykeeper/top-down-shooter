//
// Created by Admin on 03.05.2024.
//

#include <iostream>
#include "EnemyHandlingSystem.h"
#include "../../GameController.h"
#include "../../Utils.h"
#include "cmath"

auto checkHealth(auto& enemies) -> void;
auto moveEnemies(auto&, sf::Time) -> void;

void EnemyHandlingSystem::update(sf::Time dt) const {
    auto& enemies = GameController::getInstance()->enemyHandler.getItems();

    checkHealth(enemies);

    moveEnemies(enemies, dt);

    for (auto& e : GameController::getInstance()->enemiesToAdd.getItems()){
        GameController::getInstance()->enemyHandler.add(std::move(e));
    }

    GameController::getInstance()->enemiesToAdd.clear();
}

void moveEnemies(auto& enemies, sf::Time dt){

    sf::Vector2f playerPos = GameController::getInstance()->player.getPos();
    sf::Vector2f velocity;
    for(auto& enemy: enemies){
        enemy->getAnimationHandler().setAnimation("idle");

        if (!enemy->checkAttackConditions()) {
            if (enemy->getTimeTillEndOfCast() <= 0){
                velocity = enemy->getNextMove();
                enemy->move(velocity*enemy->getMoveSpeed()*dt.asSeconds());
                enemy->getAnimationHandler().setAnimation("idle");

            } else{
                enemy->updateTimeTillEndOfCast(dt.asSeconds());
                enemy->getAnimationHandler().setAnimation("cast");
            }
        } else {
            enemy->attack();
            enemy->getAnimationHandler().setAnimation("cast");
        }
    }
}

void checkHealth(auto& enemies){
    auto removedEnemies = std::vector<Enemy*>();

    auto player = &GameController::getInstance()->player;


    for(auto& enemy: enemies){
        if(enemy->getHealth() <= 0){
            auto item = std::move(enemy->provideInteractableOnDeath());
            if (item) GameController::getInstance()->interactableHandler.add(std::move(item));
            removedEnemies.push_back(enemy.get());
        }
    }

    for(auto enemy: removedEnemies) {
        GameController::getInstance()->player.enemyKilled();
        GameController::getInstance()->enemyHandler.remove(enemy);
    }
}