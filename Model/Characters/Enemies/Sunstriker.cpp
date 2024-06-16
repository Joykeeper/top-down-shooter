//
// Created by Admin on 08.06.2024.
//

#include "Sunstriker.h"
#include "../../../GameController.h"
#include "../../../Utils.h"

void Sunstriker::attack() {
    timeTillEndOfCast = CASTING_TIME;
    auto& player = GameController::getInstance()->player;
    spell->cast(player.getPos());
}

bool Sunstriker::checkAttackConditions() {
    if (spell->getTimeTillNext() > 0) return false;
    return true;
}
