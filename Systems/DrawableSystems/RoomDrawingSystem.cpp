//
// Created by Admin on 06.05.2024.
//

#include "RoomDrawingSystem.h"
#include "../../GameController.h"

void RoomDrawingSystem::draw(sf::RenderWindow &window) const {
    auto rooms = GameController::getInstance()->currentLevel->getRooms();

    for (auto room: rooms){
        sf::RectangleShape rectangle(room->getSize());
        rectangle.setFillColor(sf::Color::Yellow);
        rectangle.setPosition(room->getPos());
        window.draw(rectangle);
    }

}
