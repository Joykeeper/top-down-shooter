//
// Created by Admin on 02.05.2024.
//

#include "PlayerDrawingSystem.h"
#include "../../GameController.h"

void PlayerDrawingSystem::draw(sf::RenderWindow &window) const {
    sf::RectangleShape rectangle(sf::Vector2f(50, 50));
    auto playerPos = GameController::getInstance()->player.getPos();
    rectangle.setPosition(playerPos);
    window.draw(rectangle);
}