//
// Created by Admin on 06.05.2024.
//

#include "Room.h"
#include "../Characters/Player.h"

sf::Vector2f Room::ROOM_SIZE = sf::Vector2f (800, 800);

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
    if (this->currentWave_ > this->waves_.size()){
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
