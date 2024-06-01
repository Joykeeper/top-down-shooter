//
// Created by s30918 on 2024-05-24.
//

#include "Level.h"

std::vector<Room*> Level::getRooms(){
    auto rooms = std::vector<Room*>();
    for (auto [loc, room]: roomLocs){
        if (room == nullptr) continue;
        rooms.push_back(room);
    }
    return rooms;
}