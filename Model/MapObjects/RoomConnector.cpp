//
// Created by Admin on 05.06.2024.
//

#include "RoomConnector.h"

sf::Vector2f RoomConnector::CONNECTOR_SIZE = sf::Vector2f (400, 400);


std::vector<std::unique_ptr<Wall>> &RoomConnector::getWalls() {
    return walls_;
}
