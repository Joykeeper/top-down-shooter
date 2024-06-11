//
// Created by Admin on 05.06.2024.
//

#include "WallsCollisionSystem.h"
#include "../../GameController.h"
#include "../../Utils.h"


void WallsCollisionSystem::update(sf::Time) const {
    auto rooms = GameController::getInstance()->currentLevel->getRooms();
    auto characters = GameController::getInstance()->getCharacters();

    for (auto& room: rooms){
        for (auto& wall: room->getWalls()){
            for (auto character: characters){
                if (Utils::objectsCollide(*character, *wall)){
                    //collision
                }
            }
        }
    }
}
