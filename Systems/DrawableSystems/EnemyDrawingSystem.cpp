//
// Created by Admin on 03.05.2024.
//

#include "EnemyDrawingSystem.h"
#include "../../GameController.h"

void EnemyDrawingSystem::draw(sf::RenderWindow &window) const {


    auto& enemies = GameController::getInstance()->enemyHandler.getItems();

    for(auto& enemy: enemies){
        sf::RectangleShape enemySprite(enemy->getSize());
        enemySprite.setFillColor(sf::Color::Blue);
        enemySprite.setPosition(enemy->getPos()-enemy->getSize()/2.f);

        window.draw(enemySprite);
    }
}
