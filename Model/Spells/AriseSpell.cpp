//
// Created by Admin on 08.06.2024.
//

#include "AriseSpell.h"
#include "../../GameController.h"
#include "../Auras/WarningAura.h"
#include "../Auras/ArisingAura.h"

void AriseSpell::cast(sf::Vector2f pos) {
    timeTillNext = COOL_DOWN;

    auto graveyardRadius = 40;
    auto graveyard = std::make_unique<ArisingAura>(pos, graveyardRadius, caster);
    auto warning = std::make_unique<WarningAura>(pos, graveyardRadius, 2, COOL_DOWN,
                                                   caster, caster->getAllyOrEnemy(), std::move(graveyard));

    GameController::getInstance()->aurasToAdd.add(std::move(warning));
}
