//
// Created by Admin on 12.06.2024.
//

#include "RangeHoldingMovement.h"
#include "../../../../Utils.h"
#include "../../../../GameController.h"

sf::Vector2f RangeHoldingMovement::nextMove(sf::Vector2f curPos) {
    auto playerPos = GameController::getInstance()->player.getPos();
    if ((playerPos.x - curPos.x)*(playerPos.x - curPos.x)+(playerPos.y - curPos.y)*(playerPos.y - curPos.y) > rangeSize_*rangeSize_){
        return Utils::normalizeVector(playerPos-curPos);
    }
    return sf::Vector2f (0,0);
}
