//
// Created by Admin on 07.05.2024.
//

#include "PistolEnemy.h"
#include "../../../GameController.h"
#include "../../../Utils.h"

void PistolEnemy::attack() {
    auto player = &GameController::getInstance()->player;
    spell->cast(Utils::normalizeVector(player->getPos() - position_ ));
}

bool PistolEnemy::checkAttackConditions() {
    if (spell->getTimeTillNext() > 0) return false;

    auto playerPos = GameController::getInstance()->player.getPos();
    if (sqrt((playerPos.x - this->getPos().x)*(playerPos.x - this->getPos().x) +
            (playerPos.y - this->getPos().y)*(playerPos.y - this->getPos().y)) <= this->getShootingRadius()){
        return true;
    } else{
        return false;
    }
}

float PistolEnemy::getShootingRadius() const {
    return shootingRadius;
}
