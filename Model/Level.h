#pragma once

#include <vector>
#include <map>
#include "Room.h"
#include "SFML/Graphics.hpp"


class Level {
    std::map<std::pair<int, int>, Room*> roomLocs;
    std::vector<std::pair<std::pair<float, float>,std::pair<float, float>>> roomConnections;
public:
    Level(){
        for (auto i = 0; i < 10; i++){
            for (auto j = 0; j < 10; j++){
                roomLocs[{i,j}] = nullptr;
            }
        }

        roomLocs[{0, 0}] =  new Room(sf::Vector2f(0*Room::ROOM_SIZE.x, 0*Room::ROOM_SIZE.y));
        roomLocs[{1, 0}] =  new Room(sf::Vector2f(1*Room::ROOM_SIZE.x, 0*Room::ROOM_SIZE.y));
        roomLocs[{2, 0}] =  new Room(sf::Vector2f(2*Room::ROOM_SIZE.x, 0*Room::ROOM_SIZE.y));
        roomLocs[{2, -1}] =  new Room(sf::Vector2f(2*Room::ROOM_SIZE.x, -1*Room::ROOM_SIZE.y));
        roomLocs[{3, -1}] =  new Room(sf::Vector2f(3*Room::ROOM_SIZE.x, -1*Room::ROOM_SIZE.y));

//        roomLocs[{0, 0}] =  new Room();
//        roomLocs[{1, 0}] =  new Room();
//        roomLocs[{2, 0}] =  new Room();
//        roomLocs[{2, -1}] =  new Room();
//        roomLocs[{3, -1}] =  new Room();


//        roomConnections.push_back({{0,0}, {0,1}});
//        roomConnections.push_back({{0,1}, {0,2}});
//        roomConnections.push_back({{1,2}, {1,3}});
//        roomConnections.push_back({{1,2}, {1,3}});
    }

    std::vector<Room*> getRooms();


};
