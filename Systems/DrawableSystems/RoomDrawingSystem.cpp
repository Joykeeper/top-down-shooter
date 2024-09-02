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
            w.setPosition(wall->getPos()-sf::Vector2f (wall->getSize().x/2, wall->getSize().y/2) );
            window.draw(w);
        }

    }


    for (auto& connector: connectors){
        auto& floorSprite = connector->getFloorSprite();
        auto connectorPos = connector->getPos();

        floorSprite.setPosition(sf::Vector2f(connectorPos.x, connectorPos.y));
        window.draw(floorSprite);

        for (auto& wall: connector->getWalls()) {
            auto& wallSprite = wall->getSprite();
            wallSprite.setPosition(wall->getPos()-sf::Vector2f (wall->getSize().x/2, wall->getSize().y/2));
            window.draw(wallSprite);
        }

    }
}

void drawRooms(sf::RenderWindow &window){
    auto rooms = GameController::getInstance()->currentLevel->getRooms();

    for (auto room: rooms){
        auto roomPos = room->getPos();

        auto& floorSprite = room->getFloorSprite();

        for (auto i = 0; i < 10; ++i){
            for (auto j = 0; j < 10; ++j){
                floorSprite.setPosition(sf::Vector2f(roomPos.x+i*160, roomPos.y+j*160));
                window.draw(floorSprite);
            }
        }

        for (auto& wall: room->getWalls()) {
            auto& wallSprite = wall->getSprite();
            wallSprite.setPosition(wall->getPos()-sf::Vector2f (wall->getSize().x/2, wall->getSize().y/2));
            window.draw(wallSprite);
        }

    }
};
