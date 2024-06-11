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

public:
    static int LEVEL_SIZE;
    explicit Level(sf::Vector2f startPoint = sf::Vector2f (LEVEL_SIZE/2*(Room::ROOM_SIZE.x+RoomConnector::CONNECTOR_SIZE.x), LEVEL_SIZE/2*(Room::ROOM_SIZE.x+RoomConnector::CONNECTOR_SIZE.x))):
    playerStartPoint(startPoint){
//        for (auto i = 0; i < LEVEL_SIZE; i++){
//            for (auto j = 0; j < LEVEL_SIZE; j++){
//                roomLocs[{i,j}];// = nullptr;
//            }
//        }
        //generateLevel(7);

//        sf::Vector2f quoSize = sf::Vector2f (Room::ROOM_SIZE.x + RoomConnector::CONNECTOR_SIZE.x,
//                                             Room::ROOM_SIZE.y + RoomConnector::CONNECTOR_SIZE.y);
//
//        roomLocs[{0, 0}] = std::make_unique<Room>(sf::Vector2f(RoomConnector::CONNECTOR_SIZE.x/2 + 0*quoSize.x, RoomConnector::CONNECTOR_SIZE.y/2 + 0*quoSize.y));
//        roomLocs[{1, 0}] = std::make_unique<Room>(sf::Vector2f(RoomConnector::CONNECTOR_SIZE.x/2 +1*quoSize.x, RoomConnector::CONNECTOR_SIZE.y/2 + 0*quoSize.y));
//        roomLocs[{2, 0}] = std::make_unique<Room>(sf::Vector2f(RoomConnector::CONNECTOR_SIZE.x/2 +2*quoSize.x, RoomConnector::CONNECTOR_SIZE.y/2 + 0*quoSize.y));
//        roomLocs[{2, -1}] = std::make_unique<Room>(sf::Vector2f(RoomConnector::CONNECTOR_SIZE.x/2 +2*quoSize.x, RoomConnector::CONNECTOR_SIZE.y/2 + -1*quoSize.y));
//        roomLocs[{3, -1}] = std::make_unique<Room>(sf::Vector2f(RoomConnector::CONNECTOR_SIZE.x/2 +3*quoSize.x, RoomConnector::CONNECTOR_SIZE.y/2 + -1*quoSize.y));
//        activeRoom = roomLocs[{0,0}].get();
//
//        roomConnections.push_back({{0,0}, {1,0}});
//        roomConnections.push_back({{1,0}, {2,0}});
//        roomConnections.push_back({{2, 0}, {2,-1}});
//        roomConnections.push_back({{2,-1}, {3,-1}});
//
//        for (auto [roomLoc1, roomLoc2]: roomConnections){
//            roomConnectors.push_back(std::make_unique<RoomConnector>(roomLoc1, roomLoc2));
//        }
    }

    std::vector<Room*> getRooms();
    std::vector<std::unique_ptr<RoomConnector>>& getConnectors();

    Room* getActiveRoom();

    void setActiveRoom(Room& room);

    void generateLevel(int);

    void clearLevel();

    void openConnectors();
    void closeConnectors();

    sf::Vector2f getPlayerStartPoint() const;

};
