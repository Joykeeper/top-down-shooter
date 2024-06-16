//
// Created by Admin on 08.06.2024.
//

#include "Sunstrike.h"
#include "../../GameController.h"
#include "../Auras/WarningAura.h"
#include "../Auras/BurningAura.h"

void Sunstrike::cast(sf::Vector2f pos) {
    timeTillNext = COOL_DOWN;

    //auto playerPos = GameController::getInstance()->player.getPos();

    auto explosion = std::make_unique<BurningAura>(pos, sunstrikeRadius, 0.1, COOL_DOWN,
                                                  caster, caster->getAllyOrEnemy(), 100);
    auto sunstrike = std::make_unique<WarningAura>(pos, sunstrikeRadius, 1.5, COOL_DOWN,
                                                   caster, caster->getAllyOrEnemy(), std::move(explosion));

    GameController::getInstance()->auraHandler.add(std::move(sunstrike));
}
