//
// Created by Admin on 06.05.2024.
//

#include <iostream>
#include "RoomHandlingSystem.h"
#include "../../Model/MapObjects/Room.h"
#include "../../GameController.h"

auto checkOnEnteringNewRoom () -> void;

void RoomHandlingSystem::update(sf::Time) const {
    auto activeRoom = GameController::getInstance()->currentLevel->getActiveRoom();

    if(GameController::getInstance()->enemyHandler.getItems().empty() and !activeRoom->isFinished()){
        activeRoom->nextWave();

        auto enemies = activeRoom->provideEnemies();

        for (auto& enemy: enemies){
            GameController::getInstance()->enemyHandler.add(std::move(enemy));
        }

    }

    checkOnEnteringNewRoom();
}

auto checkOnEnteringNewRoom () -> void {
    auto rooms = GameController::getInstance()->currentLevel->getRooms();
    auto& player = GameController::getInstance()->player;
    for (auto room: rooms){
        if (room->hasPlayerEntered(player) && !room->isFinished()){
            GameController::getInstance()->currentLevel->setActiveRoom(*room);
            break;
        };
    }
}
