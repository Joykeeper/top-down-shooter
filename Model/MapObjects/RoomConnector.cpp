//
// Created by Admin on 05.06.2024.
//

#include "RoomConnector.h"
#include "Room.h"

sf::Vector2f RoomConnector::CONNECTOR_SIZE = sf::Vector2f (400, 400);


std::vector<std::unique_ptr<Wall>> &RoomConnector::getWalls() {
    return walls_;
}

sf::Vector2f RoomConnector::getPos() const {
    return position_;
}

sf::Vector2f RoomConnector::getSize() const {
    return RoomConnector::CONNECTOR_SIZE;
}

sf::Vector2f RoomConnector::calculateConnectorPos(std::pair<int, int> roomLoc1, std::pair<int, int> roomLoc2) {
    sf::Vector2f quoSize = sf::Vector2f (Room::ROOM_SIZE.x + RoomConnector::CONNECTOR_SIZE.x,
                                         Room::ROOM_SIZE.y + RoomConnector::CONNECTOR_SIZE.y);

    bool vertical = (roomLoc1.first - roomLoc2.first == 0);

    sf::Vector2f connectorPos;
    if (vertical){
        if (roomLoc1.second < roomLoc2.second){
            roomLoc2 = roomLoc1;
        }

        connectorPos = sf::Vector2f(roomLoc2.first*quoSize.x, roomLoc2.second*quoSize.y) +
                       sf::Vector2f( quoSize.x/2 - RoomConnector::CONNECTOR_SIZE.x/2,
                                     RoomConnector::CONNECTOR_SIZE.y/2+Room::ROOM_SIZE.y);
    } else {
        if (roomLoc1.first > roomLoc2.first){
            roomLoc1 = roomLoc2;
        }

        connectorPos = sf::Vector2f(roomLoc1.first*quoSize.x, roomLoc1.second*quoSize.y) +
                       sf::Vector2f( Room::ROOM_SIZE.x + RoomConnector::CONNECTOR_SIZE.x/2, quoSize.y / 2 - RoomConnector::CONNECTOR_SIZE.y/2);
    }

    return connectorPos;
}

std::pair<std::pair<int, int>, std::pair<int, int>> RoomConnector::getConnectionLocs() {
    return connectionBetweenRooms;
}

void RoomConnector::openConnector() {
    walls_.clear();

    auto vertical = connectionBetweenRooms.first.first - connectionBetweenRooms.second.first == 0;

    if (!vertical){
        for (auto i = 0; i < CONNECTOR_SIZE.x/40; i++){
            walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f (i*40, 0)));
            walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f (i*40, CONNECTOR_SIZE.y-40)));
        }
    }
    else {
        for (auto i = 0; i < CONNECTOR_SIZE.y/40; i++){
            walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f (0, i*40)));
            walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f (CONNECTOR_SIZE.x-40, i*40)));
        }
    }
}

void RoomConnector::closeConnector() {
    walls_.clear();

    auto vertical = connectionBetweenRooms.first.first - connectionBetweenRooms.second.first == 0;

    if (!vertical){
        for (auto i = 0; i < CONNECTOR_SIZE.x/40; i++){
            walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f (i*40, 0)));
            walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f (i*40, CONNECTOR_SIZE.y-40)));

            walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f (0, i*40)));
            walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f (CONNECTOR_SIZE.x-40, i*40)));
        }
    }
    else {
        for (auto i = 0; i < CONNECTOR_SIZE.y/40; i++){
            walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f (i*40, 0)));
            walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f (i*40, CONNECTOR_SIZE.y-40)));

            walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f (0, i*40)));
            walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f (CONNECTOR_SIZE.x-40, i*40)));
        }
    }
}

bool RoomConnector::isClosed() {
    return closed_;
}
