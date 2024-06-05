//
// Created by s30918 on 2024-05-24.
//

#include "Level.h"


std::vector<Room*> Level::getRooms(){
    auto rooms = std::vector<Room*>();
    for (auto [loc, room]: this->roomLocs){
        if (room == nullptr) continue;
        rooms.push_back(room);
    }
    return rooms;
}

Room* Level::getActiveRoom() {
    return this->activeRoom;
}

void Level::setActiveRoom(Room& room) {
    this->activeRoom = &room;
}

std::vector<std::unique_ptr<RoomConnector>> &Level::getConnectors() {
    return roomConnectors;
}
