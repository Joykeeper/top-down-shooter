#pragma once

#include <vector>
#include <map>
#include "Room.h"
#include "SFML/Graphics.hpp"
#include "RoomConnector.h"
#include <iostream>


class Level {
    std::map<std::pair<int, int>, Room*> roomLocs = std::map<std::pair<int, int>, Room*>();
    Room* activeRoom;
    std::vector<std::pair<std::pair<float, float>,std::pair<float, float>>> roomConnections;
    std::vector<std::unique_ptr<RoomConnector>> roomConnectors;
public:
    explicit Level(){
        for (auto i = 0; i < 10; i++){
            for (auto j = 0; j < 10; j++){
                roomLocs[{i,j}] = nullptr;
            }
        }
        std::cout << roomLocs.size();

        sf::Vector2f quoSize = sf::Vector2f (Room::ROOM_SIZE.x + RoomConnector::CONNECTOR_SIZE.x,
                                             Room::ROOM_SIZE.y + RoomConnector::CONNECTOR_SIZE.y);

        roomLocs[{0, 0}] = new Room(sf::Vector2f(RoomConnector::CONNECTOR_SIZE.x/2 + 0*quoSize.x, RoomConnector::CONNECTOR_SIZE.y/2 + 0*quoSize.y));
        roomLocs[{1, 0}] = new Room(sf::Vector2f(RoomConnector::CONNECTOR_SIZE.x/2 +1*quoSize.x, RoomConnector::CONNECTOR_SIZE.y/2 + 0*quoSize.y));
        roomLocs[{2, 0}] = new Room(sf::Vector2f(RoomConnector::CONNECTOR_SIZE.x/2 +2*quoSize.x, RoomConnector::CONNECTOR_SIZE.y/2 + 0*quoSize.y));
        roomLocs[{2, -1}] = new Room(sf::Vector2f(RoomConnector::CONNECTOR_SIZE.x/2 +2*quoSize.x, RoomConnector::CONNECTOR_SIZE.y/2 + -1*quoSize.y));
        roomLocs[{3, -1}] = new Room(sf::Vector2f(RoomConnector::CONNECTOR_SIZE.x/2 +3*quoSize.x, RoomConnector::CONNECTOR_SIZE.y/2 + -1*quoSize.y));
        activeRoom = roomLocs[{0,0}];
//        roomLocs[{0, 0}] =  new Room();
//        roomLocs[{1, 0}] =  new Room();
//        roomLocs[{2, 0}] =  new Room();
//        roomLocs[{2, -1}] =  new Room();
//        roomLocs[{3, -1}] =  new Room();


        roomConnections.push_back({{0,0}, {1,0}});
        roomConnections.push_back({{1,0}, {2,0}});
        roomConnections.push_back({{2, 0}, {2,-1}});
        roomConnections.push_back({{2,-1}, {3,-1}});

        for (auto [roomLoc1, roomLoc2]: roomConnections){
            bool vertical = (roomLoc1.first - roomLoc2.first == 0);

            sf::Vector2f connectorPos;
            if (vertical){
                connectorPos = sf::Vector2f(roomLoc2.first*quoSize.x, roomLoc2.second*quoSize.y) +
                        sf::Vector2f( quoSize.x/2 - RoomConnector::CONNECTOR_SIZE.x/2,
                                      RoomConnector::CONNECTOR_SIZE.y/2+Room::ROOM_SIZE.y);
            } else {
                connectorPos = sf::Vector2f(roomLoc1.first*quoSize.x, roomLoc1.second*quoSize.y) +
                                    sf::Vector2f( Room::ROOM_SIZE.x + RoomConnector::CONNECTOR_SIZE.x/2, quoSize.y / 2 - RoomConnector::CONNECTOR_SIZE.y/2);
            }
            roomConnectors.push_back(std::make_unique<RoomConnector>(connectorPos, vertical));
        }
    }

    std::vector<Room*> getRooms();
    std::vector<std::unique_ptr<RoomConnector>>& getConnectors();

    Room* getActiveRoom();

    void setActiveRoom(Room& room);


};
