//
// Created by Admin on 03.05.2024.
//

#include "EnemyDrawingSystem.h"
#include "../../GameController.h"

void EnemyDrawingSystem::draw(sf::RenderWindow &window) const {
    sf::RectangleShape enemySprite(sf::Vector2f(75, 75));
    enemySprite.setFillColor(sf::Color::Blue);

    auto enemies = GameController::getInstance()->enemyHandler.getItems();

    for(auto& enemy: enemies){
        enemySprite.setPosition(enemy->getPos());

        window.draw(enemySprite);
    }
}
