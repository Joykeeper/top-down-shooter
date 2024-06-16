#pragma once

#include <vector>
#include <map>
#include "Room.h"
#include "SFML/Graphics.hpp"
#include "RoomConnector.h"
#include <iostream>


class Level {
    std::map<std::pair<int, int>, std::unique_ptr<Room>> roomLocs = std::map<std::pair<int, int>, std::unique_ptr<Room>>();
    Room* activeRoom;
    std::vector<std::pair<std::pair<float, float>,std::pair<float, float>>> roomConnections;
    std::vector<std::unique_ptr<RoomConnector>> roomConnectors;

    sf::Vector2f playerStartPoint;

    bool levelCompleted;

public:
    static int LEVEL_SIZE;
    explicit Level(sf::Vector2f startPoint = sf::Vector2f (LEVEL_SIZE/2*(Room::ROOM_SIZE.x+RoomConnector::CONNECTOR_SIZE.x), LEVEL_SIZE/2*(Room::ROOM_SIZE.x+RoomConnector::CONNECTOR_SIZE.x))):
    playerStartPoint(startPoint), levelCompleted(false){};

    std::vector<Room*> getRooms();
    std::vector<std::unique_ptr<RoomConnector>>& getConnectors();

    Room* getActiveRoom();

    void setActiveRoom(Room& room);

    void generateLevel(int);

    void clearLevel();

    bool isCompleted();
    void setCompleted(bool);

    void openConnectors();
    void closeConnectors();

    sf::Vector2f getPlayerStartPoint() const;

};
