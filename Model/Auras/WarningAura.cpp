//
// Created by Admin on 11.06.2024.
//

#include "WarningAura.h"
#include "../../GameController.h"

void WarningAura::actionOnEnd() {
    GameController::getInstance()->aurasToAdd.add(std::move(auraToPut));
}
