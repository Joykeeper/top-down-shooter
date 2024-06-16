//
// Created by Admin on 05.06.2024.
//

#include "MovementFromPlayer.h"
#include "../../../../GameController.h"
#include "../../../../Utils.h"

sf::Vector2f MovementFromPlayer::nextMove(sf::Vector2f curPos) {
    auto player = &GameController::getInstance()->player;
    return Utils::normalizeVector(curPos - player->getPos());;
}
