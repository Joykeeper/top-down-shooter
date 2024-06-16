//
// Created by Admin on 16.06.2024.
//

#include "PieceOfHell.h"
#include "../../GameController.h"
#include "../Auras/BurningAura.h"
#include "../Auras/WarningAura.h"

void PieceOfHell::cast(sf::Vector2f pos) {
    timeTillNext = COOL_DOWN;

    auto hell = std::make_unique<BurningAura>(pos, radius, auraTime, 0.3,
                                                   caster, caster->getAllyOrEnemy(), 1);

    GameController::getInstance()->auraHandler.add(std::move(hell));
}
