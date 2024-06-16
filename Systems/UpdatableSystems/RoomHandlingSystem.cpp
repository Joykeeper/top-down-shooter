//
// Created by Admin on 06.05.2024.
//

#include <iostream>
#include "RoomHandlingSystem.h"
#include "../../Model/MapObjects/Room.h"
#include "../../GameController.h"
#include "../../Model/Scenes/SkillSelectionScene.h"

auto checkOnEnteringNewRoom () -> void;

void RoomHandlingSystem::update(sf::Time) const {
    auto activeRoom = GameController::getInstance()->currentLevel->getActiveRoom();
    auto& level = GameController::getInstance()->currentLevel;


    if(GameController::getInstance()->enemyHandler.getItems().empty() and !activeRoom->isFinished()){
        activeRoom->nextWave();

        auto enemies = activeRoom->provideEnemies();

        for (auto& enemy: enemies){
            GameController::getInstance()->enemyHandler.add(std::move(enemy));
        }

    }

    checkOnEnteringNewRoom();


    if (activeRoom->isFinished()){
//        if (GameController::getInstance()->unusedSkillPoints != 0){
//            GameController::getInstance()->sceneManager.changeScene(std::make_unique<SkillSelectionScene>(Weapon::generateActiveSkills(2), Weapon::generatePassiveSkills(1)));
//            GameController::getInstance()->unusedSkillPoints--;
//        }
        level->openConnectors();
    } else{
        level->closeConnectors();
    }

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
