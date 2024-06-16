//
// Created by Admin on 06.05.2024.
//

#include "Room.h"
#include <iostream>
#include "../Characters/Player.h"
#include "../../GameController.h"
#include "../../Utils.h"
#include "../Interactables/GateToNextLevel.h"
#include "../Characters/Enemies/UpperNecromancer.h"

sf::Vector2f Room::ROOM_SIZE = sf::Vector2f (1600, 1600);

sf::Vector2f Room::getPos() {
    return this->position_;
}

sf::Vector2f Room::getSize() {
    return this->size_;
}

int Room::getCurrentWave() const{
    return this->currentWave_;
}

void Room::nextWave() {
    if (this->currentWave_ == this->waves_.size()-1){
        this->finished = true;
    }else{
        this->currentWave_++;
    }
}

bool Room::isFinished() const {
    return finished;
}

std::vector<std::unique_ptr<Enemy>>& Room::getCurrentEnemies() {
    return this->waves_[this->currentWave_];
}

std::vector<std::unique_ptr<Enemy>> Room::provideEnemies() {
    auto providedEnemies = std::vector<std::unique_ptr<Enemy>>();
    auto& enemies = this->waves_[this->currentWave_];
    for(auto& enemy: enemies){
        providedEnemies.push_back(std::move(enemy));
    }
    this->waves_[this->currentWave_] = std::vector<std::unique_ptr<Enemy>>();
    return providedEnemies;
}

bool Room::hasPlayerEntered(Player& player) {
    auto playerPos = player.getPos();
    auto roomPos = this->getPos();

    return (playerPos.x >= roomPos.x && playerPos.x <= roomPos.x + ROOM_SIZE.x)
    && (playerPos.y >= roomPos.y && playerPos.y <= roomPos.y + ROOM_SIZE.y);
}

std::vector<std::unique_ptr<Wall>> &Room::getWalls() {
    return walls_;
}

sf::Vector2f Room::calculateRoomPosition(std::pair<int, int> pos) {
    sf::Vector2f quoSize = sf::Vector2f (Room::ROOM_SIZE.x + RoomConnector::CONNECTOR_SIZE.x,
                                             Room::ROOM_SIZE.y + RoomConnector::CONNECTOR_SIZE.y);

    return sf::Vector2f(RoomConnector::CONNECTOR_SIZE.x/2 + pos.first*quoSize.x, RoomConnector::CONNECTOR_SIZE.y/2 + pos.second*quoSize.y);

}

void Room::setRoomConnections(std::vector<RoomConnections>& rc) {
    this->roomConnections = rc;
    updateWalls();
}

void Room::updateWalls() {
    walls_.clear();

    float conStartPos = (ROOM_SIZE.y/2-RoomConnector::CONNECTOR_SIZE.y/2) /40;

    auto right = std::find(roomConnections.begin(), roomConnections.end(),RoomConnections::RIGHT)==roomConnections.end();
    auto top = std::find(roomConnections.begin(), roomConnections.end(),RoomConnections::TOP)==roomConnections.end();
    auto left = std::find(roomConnections.begin(), roomConnections.end(),RoomConnections::LEFT)==roomConnections.end();
    auto bottom = std::find(roomConnections.begin(), roomConnections.end(),RoomConnections::BOTTOM)==roomConnections.end();

    for (auto i = 0; i < ROOM_SIZE.x/40; i++){
        if( i > conStartPos && i < conStartPos + RoomConnector::CONNECTOR_SIZE.y/ 40 - 1){
            if (top){
                walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f (i*40, 0) + sf::Vector2f(Wall::WALL_SIZE.x/2, Wall::WALL_SIZE.y/2)));
            }
            if (right){
                walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f(ROOM_SIZE.x-40, i * 40) + sf::Vector2f(Wall::WALL_SIZE.x/2, Wall::WALL_SIZE.y/2)));
            }
            if (bottom){
                walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f (i*40, ROOM_SIZE.y-40) + sf::Vector2f(Wall::WALL_SIZE.x/2, Wall::WALL_SIZE.y/2)));
            }
            if (left){
                walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f (0, i*40) + sf::Vector2f(Wall::WALL_SIZE.x/2, Wall::WALL_SIZE.y/2)));
            }
        } else {
            walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f (i*40, 0) + sf::Vector2f(Wall::WALL_SIZE.x/2, Wall::WALL_SIZE.y/2)));
            walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f(ROOM_SIZE.x-40, i * 40) + sf::Vector2f(Wall::WALL_SIZE.x/2, Wall::WALL_SIZE.y/2)));
            walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f (i*40, ROOM_SIZE.y-40) + sf::Vector2f(Wall::WALL_SIZE.x/2, Wall::WALL_SIZE.y/2)));
            walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f (0, i*40) + sf::Vector2f(Wall::WALL_SIZE.x/2, Wall::WALL_SIZE.y/2)));

        }
    }
}

void Room::generateWaves(int difficultyLevel) {
    waves_.clear();

    auto roomSize = sf::Vector2f(ROOM_SIZE.x - 300, ROOM_SIZE.y - 300);

    if (difficultyLevel == 0){
        //no enemies
    } else if (difficultyLevel == -1){
        GameController::getInstance()->interactableHandler.add(std::make_unique<GateToNextLevel>(position_ + sf::Vector2f(ROOM_SIZE.x/2, ROOM_SIZE.y/2)));
    }
    else if (difficultyLevel == 1){
        auto amountOfWaves = Utils::generateNumberInRange(1, 2);
        for (auto i = 0; i < amountOfWaves; i++){

            auto amountOfEnemies = Utils::generateNumberInRange(2, 5);

            auto x = Utils::generateNumberInRange(0, roomSize.x);
            auto y = Utils::generateNumberInRange(0, roomSize.y);

            for (auto e = 0; e < amountOfEnemies; e++) {

                std::unique_ptr<Enemy> enemy = std::make_unique<PistolEnemy>(position_ + sf::Vector2f(x, y) + sf::Vector2f(150, 150));

                x = Utils::generateNumberInRange(0, roomSize.x);
                y = Utils::generateNumberInRange(0, roomSize.y);

                waves_[i].push_back(std::move(enemy));
            }

        }

    } else if (difficultyLevel == 2){

        auto amountOfWaves = Utils::generateNumberInRange(2, 4);

        for (auto i = 0; i < amountOfWaves; i++){

            auto amountOfEnemies = Utils::generateNumberInRange(2, 5);

            auto x = Utils::generateNumberInRange(0, roomSize.x);
            auto y = Utils::generateNumberInRange(0, roomSize.y);

            for (auto e = 0; e < amountOfEnemies; e++) {

                auto typeOfEnemy = Utils::generateNumberInRange(0, 2);
                std::unique_ptr<Enemy> enemy;
                if (typeOfEnemy == 0) {
                    enemy = std::make_unique<PistolEnemy>(position_ + sf::Vector2f(x, y) + sf::Vector2f(150, 150));
                } else if (typeOfEnemy == 1) {
                    enemy = std::make_unique<Sunstriker>(position_ + sf::Vector2f(x, y) + sf::Vector2f(150, 150));
                }

                x = Utils::generateNumberInRange(0, roomSize.x);
                y = Utils::generateNumberInRange(0, roomSize.y);

                waves_[i].push_back(std::move(enemy));
            }

        }

    } else if (difficultyLevel == 3){

        auto amountOfWaves = Utils::generateNumberInRange(3, 4);


        for (auto i = 0; i < amountOfWaves; i++){

            auto amountOfEnemies = Utils::generateNumberInRange(2, 5);

            auto x = Utils::generateNumberInRange(0, roomSize.x);
            auto y = Utils::generateNumberInRange(0, roomSize.y);

            for (auto e = 0; e < amountOfEnemies; e++) {

                auto typeOfEnemy = Utils::generateNumberInRange(0, 3);
                std::unique_ptr<Enemy> enemy;
                if (typeOfEnemy == 0) {
                    enemy = std::make_unique<PistolEnemy>(position_ + sf::Vector2f(x, y) + sf::Vector2f(150, 150));
                } else if (typeOfEnemy == 1) {
                    enemy = std::make_unique<Sunstriker>(position_ + sf::Vector2f(x, y) + sf::Vector2f(150, 150));
                } else if (typeOfEnemy == 2) {
                    enemy = std::make_unique<Necromancer>(position_ + sf::Vector2f(x, y) + sf::Vector2f(150, 150));
                }

                x = Utils::generateNumberInRange(0, roomSize.x);
                y = Utils::generateNumberInRange(0, roomSize.y);

                waves_[i].push_back(std::move(enemy));
            }

        }

    } else if (difficultyLevel == 4){

        auto enemy = std::make_unique<UpperNecromancer>(position_ + sf::Vector2f(ROOM_SIZE.x/2, ROOM_SIZE.y/2) );
        waves_[0].push_back(std::move(enemy));
    }



}

int Room::getNumber() const {
    return numberInLevel;
}
