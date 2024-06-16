//
// Created by Admin on 05.06.2024.
//

#include "RandomMovement.h"
#include "../../../../GameController.h"
#include "../../../../Utils.h"

sf::Vector2f RandomMovement::nextMove(sf::Vector2f curPos) {
    auto room = GameController::getInstance()->currentLevel->getActiveRoom();
    auto roomSize = sf::Vector2f(Room::ROOM_SIZE.x - 300, Room::ROOM_SIZE.y - 300);


    if (curPos.x - selectedDir_.x < 1 && curPos.y - selectedDir_.y < 1){
        auto x = Utils::generateNumberInRange(0, roomSize.x);
        auto y = Utils::generateNumberInRange(0, roomSize.y);
        selectedDir_ = sf::Vector2f (room->getPos().x + x,room->getPos().y + y) + sf::Vector2f (150, 150);
    }


    return Utils::normalizeVector(selectedDir_ - curPos);
}
