//
// Created by Admin on 06.05.2024.
//

#include <iostream>
#include "RoomHandlingSystem.h"
#include "../../Model/Room.h"
#include "../../GameController.h"

void RoomHandlingSystem::update(sf::Time) const {
    auto activeRoom = GameController::getInstance()->activeRoom;

    if(GameController::getInstance()->enemyHandler.getItems().empty() and !activeRoom->isFinished()){
        activeRoom->nextWave();

        auto enemies = activeRoom->provideEnemies();

        GameController::getInstance()->enemyHandler.addAll(enemies);
    }
}
