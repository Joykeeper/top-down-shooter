//
// Created by Admin on 02.05.2024.
//

#include "PlayerDrawingSystem.h"
#include "../../GameController.h"

void PlayerDrawingSystem::draw(sf::RenderWindow &window) const {
    auto player = &GameController::getInstance()->player;

    sf::RectangleShape rectangle(player->getSize());
    rectangle.setPosition(player->getPos() - player->getSize()/2.f);
    window.draw(rectangle);
}