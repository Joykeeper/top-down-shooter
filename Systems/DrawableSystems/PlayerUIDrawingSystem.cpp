//
// Created by Admin on 11.06.2024.
//

#include "PlayerUIDrawingSystem.h"
#include "../../GameController.h"

void PlayerUIDrawingSystem::draw(sf::RenderWindow &window) const {
    auto mainView = window.getView();
    window.setView(window.getDefaultView());

    auto& player = GameController::getInstance()->player;

    sf::RectangleShape heartIcon(sf::Vector2f(40, 40));
    heartIcon.setFillColor(sf::Color::Red);
    heartIcon.setPosition(sf::Vector2f(20, 40));
    window.draw(heartIcon);

    sf::RectangleShape healthBar(sf::Vector2f(200, 40));
    healthBar.setPosition(sf::Vector2f(70, 40));
    window.draw(healthBar);

    sf::RectangleShape curHealth(sf::Vector2f(((float )player.getHealth()/50)*200, 40));
    curHealth.setFillColor(sf::Color::Red);
    curHealth.setPosition(sf::Vector2f(70, 40));
    window.draw(curHealth);


    sf::RectangleShape shieldIcon(sf::Vector2f(40, 40));
    shieldIcon.setFillColor(sf::Color::Blue);
    shieldIcon.setPosition(sf::Vector2f(20, 110));
    window.draw(shieldIcon);

    sf::RectangleShape curShield(sf::Vector2f(((float )player.getShieldPoints()/40)*200, 40));
    curShield.setFillColor(sf::Color::Blue);
    curShield.setPosition(sf::Vector2f(70, 110));
    window.draw(curShield);

    window.setView(mainView);
}
