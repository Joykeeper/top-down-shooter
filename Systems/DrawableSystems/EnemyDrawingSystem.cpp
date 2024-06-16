//
// Created by Admin on 03.05.2024.
//

#include "EnemyDrawingSystem.h"
#include "../../GameController.h"

void drawHealthBars(sf::RenderWindow &);

void EnemyDrawingSystem::draw(sf::RenderWindow &window) const {


    auto& enemies = GameController::getInstance()->enemyHandler.getItems();

    for(auto& enemy: enemies){
        sf::RectangleShape enemySprite(enemy->getSize());
        enemySprite.setFillColor(enemy->getColor());
        enemySprite.setPosition(enemy->getPos()-enemy->getSize()/2.f);

        window.draw(enemySprite);
    }

    drawHealthBars(window);
}

void drawHealthBars(sf::RenderWindow &window){
    auto& enemies = GameController::getInstance()->enemyHandler.getItems();

    for(auto& enemy: enemies){
        sf::RectangleShape healthBar(sf::Vector2f(enemy->getSize().x, 5));
        healthBar.setFillColor(sf::Color::White);
        healthBar.setPosition(sf::Vector2f(enemy->getPos().x - enemy->getSize().x/2, enemy->getPos().y + enemy->getSize().y/2+7));

        window.draw(healthBar);

        sf::RectangleShape remainingHealth(sf::Vector2f(enemy->getSize().x*((float )enemy->getHealth()/(float )enemy->getMaxHealth()), 5));
        remainingHealth.setFillColor(sf::Color::Red);
        remainingHealth.setPosition(sf::Vector2f(enemy->getPos().x - enemy->getSize().x/2, enemy->getPos().y + enemy->getSize().y/2+7));

        window.draw(remainingHealth);
    }
};
