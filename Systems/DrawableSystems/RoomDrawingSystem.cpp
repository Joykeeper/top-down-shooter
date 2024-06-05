//
// Created by Admin on 06.05.2024.
//

#include "RoomDrawingSystem.h"
#include "../../GameController.h"


void drawConnectors(sf::RenderWindow &window);
void drawRooms(sf::RenderWindow &window);

void RoomDrawingSystem::draw(sf::RenderWindow &window) const {

    drawRooms(window);
    drawConnectors(window);

}


void drawConnectors(sf::RenderWindow &window){
    auto& connectors = GameController::getInstance()->currentLevel->getConnectors();

    for (auto& connector: connectors){
        sf::RectangleShape rectangle(connector->getSize());
        rectangle.setFillColor(sf::Color::Magenta);
        rectangle.setPosition(connector->getPos());
        window.draw(rectangle);

        for (auto& wall: connector->getWalls()) {
            sf::RectangleShape w(wall->getSize());
            w.setFillColor(sf::Color::Red);
            w.setPosition(wall->getPos());
            window.draw(w);
        }

    }
}

void drawRooms(sf::RenderWindow &window){
    auto rooms = GameController::getInstance()->currentLevel->getRooms();

    for (auto room: rooms){
        sf::RectangleShape rectangle(room->getSize());
        rectangle.setFillColor(sf::Color::Yellow);
        rectangle.setPosition(room->getPos());
        window.draw(rectangle);

        for (auto& wall: room->getWalls()) {
            sf::RectangleShape w(wall->getSize());
            w.setFillColor(sf::Color::Red);
            w.setPosition(wall->getPos());
            window.draw(w);
        }

    }
};
