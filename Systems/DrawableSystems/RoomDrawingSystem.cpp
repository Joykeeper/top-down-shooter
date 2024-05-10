//
// Created by Admin on 06.05.2024.
//

#include "RoomDrawingSystem.h"
#include "../../GameController.h"

void RoomDrawingSystem::draw(sf::RenderWindow &window) const {
    auto room = GameController::getInstance()->activeRoom;

    sf::RectangleShape rectangle(room->getSize());
    rectangle.setFillColor(sf::Color::Yellow);
    rectangle.setPosition(room->getPos());
    window.draw(rectangle);
}
