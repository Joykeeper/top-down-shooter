//
// Created by s30918 on 2024-05-24.
//

#include "Level.h"
#include <random>

int Level::LEVEL_SIZE = 7;

std::vector<Room*> Level::getRooms(){
    auto rooms = std::vector<Room*>();
    for (auto& [loc, room]: this->roomLocs){
        if (!room) continue;
        rooms.push_back(room.get());
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

void Level::clearLevel(){
    roomConnectors.clear();
    roomLocs.clear();
}


void Level::generateLevel(int roomCount) {
    clearLevel();

    auto currentRoomLoc = std::pair<int, int>(LEVEL_SIZE/2,LEVEL_SIZE/2);

    auto availableDirs = std::vector<RoomConnections>();

    for (int i = 0; i < roomCount; i++) {
        roomLocs[currentRoomLoc] = std::make_unique<Room>(currentRoomLoc);

        if (!roomLocs[{currentRoomLoc.first + 1, currentRoomLoc.second + 0}] &&
            currentRoomLoc.first + 1 < LEVEL_SIZE){
            availableDirs.push_back(RoomConnections::RIGHT);
        }
        if (!roomLocs[{currentRoomLoc.first + 0, currentRoomLoc.second - 1}] &&
            currentRoomLoc.second - 1 >= LEVEL_SIZE){
            availableDirs.push_back(RoomConnections::TOP);
        }
        if (!roomLocs[{currentRoomLoc.first - 1, currentRoomLoc.second + 0}] &&
            currentRoomLoc.first - 1 >= 0){
            availableDirs.push_back(RoomConnections::LEFT);
        }
        if (!roomLocs[{currentRoomLoc.first + 0, currentRoomLoc.second + 1}] &&
            currentRoomLoc.second + 1 < LEVEL_SIZE){
            availableDirs.push_back(RoomConnections::BOTTOM);
        }

        std::cout << availableDirs.size() << " -level availabledirs\n";

        if (availableDirs.empty()) break;

        const int range_from = 0;
        const int range_to = availableDirs.size()-1;
        std::random_device rand_dev;
        std::mt19937 generator(rand_dev());
        std::uniform_int_distribution<int> distr(range_from, range_to);
        auto dir = distr(generator);

        auto newRoomLoc = std::pair<int, int>();

        switch (availableDirs[dir]) {
            case RoomConnections::TOP:
                newRoomLoc = std::pair<int, int>(currentRoomLoc.first+0,currentRoomLoc.second-1);

                roomConnectors.push_back(std::make_unique<RoomConnector>(currentRoomLoc, newRoomLoc));
                currentRoomLoc = newRoomLoc;
                break;
            case RoomConnections::RIGHT:
                newRoomLoc = std::pair<int, int>(currentRoomLoc.first+1,currentRoomLoc.second+0);

                roomConnectors.push_back(std::make_unique<RoomConnector>(currentRoomLoc, newRoomLoc));
                currentRoomLoc = newRoomLoc;
                break;
            case RoomConnections::LEFT:
                newRoomLoc = std::pair<int, int>(currentRoomLoc.first-1,currentRoomLoc.second+0);

                roomConnectors.push_back(std::make_unique<RoomConnector>(currentRoomLoc, newRoomLoc));
                currentRoomLoc = newRoomLoc;
                break;
            case RoomConnections::BOTTOM:
                newRoomLoc = std::pair<int, int>(currentRoomLoc.first+0,currentRoomLoc.second+1);

                roomConnectors.push_back(std::make_unique<RoomConnector>(currentRoomLoc, newRoomLoc));
                currentRoomLoc = newRoomLoc;
                break;
            default:
                break;
        }
        availableDirs.clear();
    }

    auto noWallSides = std::vector<RoomConnections>();
    for (auto& [loc , room]: this->roomLocs){
        if (!room) continue;

        for (auto& connector: roomConnectors){
            if (connector->getConnectionLocs().first == loc){
                auto side = std::pair<int, int>(connector->getConnectionLocs().second.first - connector->getConnectionLocs().first.first, connector->getConnectionLocs().second.second - connector->getConnectionLocs().first.second);

                if (side == std::pair<int, int>(1, 0)){
                    noWallSides.push_back(RoomConnections::RIGHT);
                } else if (side == std::pair<int, int>(-1, 0)){
                    noWallSides.push_back(RoomConnections::LEFT);
                } else if (side == std::pair<int, int>(0, -1)){
                    noWallSides.push_back(RoomConnections::TOP);
                } else if (side == std::pair<int, int>(0, 1)){
                    noWallSides.push_back(RoomConnections::BOTTOM);
                }
            } else if (connector->getConnectionLocs().second == loc){
                auto side = std::pair<int, int>(connector->getConnectionLocs().first.first - connector->getConnectionLocs().second.first, connector->getConnectionLocs().first.second - connector->getConnectionLocs().second.second);

                if (side == std::pair<int, int>(1, 0)){
                    noWallSides.push_back(RoomConnections::RIGHT);
                } else if (side == std::pair<int, int>(-1, 0)){
                    noWallSides.push_back(RoomConnections::LEFT);
                } else if (side == std::pair<int, int>(0, -1)){
                    noWallSides.push_back(RoomConnections::TOP);
                } else if (side == std::pair<int, int>(0, 1)){
                    noWallSides.push_back(RoomConnections::BOTTOM);
                }
            }
        }

        room->setRoomConnections(noWallSides);
        noWallSides.clear();
    }

    activeRoom = roomLocs[{LEVEL_SIZE/2,LEVEL_SIZE/2}].get();
    playerStartPoint = activeRoom->getPos() + sf::Vector2f (Room::ROOM_SIZE.x/2, Room::ROOM_SIZE.y/2);
}

sf::Vector2f Level::getPlayerStartPoint() const {
    return playerStartPoint;
}

void Level::openConnectors() {
    for (auto& connector: roomConnectors){
        //if (connector->isClosed()){
            connector->openConnector();
        //}
    }
}

void Level::closeConnectors() {
    for (auto& connector: roomConnectors){
        //if (!connector->isClosed()){
            connector->closeConnector();
        //}
    }
}
