//
// Created by Admin on 05.06.2024.
//

#include "MovementTowardsPlayer.h"
#include "../../../../Utils.h"
#include "../../../../GameController.h"

sf::Vector2f MovementTowardsPlayer::nextMove(sf::Vector2f curPos) {
    auto player = &GameController::getInstance()->player;
    return Utils::normalizeVector(player->getPos()-curPos);;
}
