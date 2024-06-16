//
// Created by s30918 on 2024-05-24.
//

#include "Level.h"
#include "../../Utils.h"

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
        roomLocs[currentRoomLoc] = std::make_unique<Room>(currentRoomLoc, i);

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


        auto dir = Utils::generateNumberInRange(0, availableDirs.size());

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

    auto i = 0;
    auto filledRoomsSize = (float) getRooms().size();
    for (auto& [loc, room]: roomLocs){
        if (!room) continue;

        auto percentage = ((float )(room->getNumber()+1)/filledRoomsSize)*100;

        if (room->getNumber() == 0){
            room->generateWaves(0);
        }else if (room->getNumber() == filledRoomsSize - 1){
            room->generateWaves(-1);
        }
        else if (room->getNumber() == filledRoomsSize - 2){
            room->generateWaves(4);
        } else if (70 <= percentage){
            room->generateWaves(3);
        } else if (40 <= percentage){
            room->generateWaves(2);
        } else{
            room->generateWaves(1);
        }
        i++;

    }

    activeRoom = roomLocs[{LEVEL_SIZE/2,LEVEL_SIZE/2}].get();
    playerStartPoint = activeRoom->getPos() + sf::Vector2f (Room::ROOM_SIZE.x/2, Room::ROOM_SIZE.y/2);
}

sf::Vector2f Level::getPlayerStartPoint() const {
    return playerStartPoint;
}

void Level::openConnectors() {
    for (auto& connector: roomConnectors){
        connector->openConnector();
    }
}

void Level::closeConnectors() {
    for (auto& connector: roomConnectors){
            connector->closeConnector();
    }
}

bool Level::isCompleted() {
    return levelCompleted;
}

void Level::setCompleted(bool b) {
    levelCompleted = b;
}
