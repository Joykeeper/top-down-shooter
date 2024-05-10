//
// Created by Admin on 06.05.2024.
//

#include "Room.h"

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

void Room::start() {
    this->active = true;
}

bool Room::isActive() const {
    return active;
}

bool Room::isFinished() const {
    return finished;
}

std::vector<Enemy *> Room::getCurrentEnemies() {
    return this->waves_[this->currentWave_];
}

std::vector<Enemy *> Room::provideEnemies() {
    auto enemies = this->waves_[this->currentWave_];
    this->waves_[this->currentWave_] = {};
    return enemies;
}
