//
// Created by Admin on 08.06.2024.
//

#include "BallSpell.h"
#include "../../GameController.h"

void BallSpell::cast(sf::Vector2f dir) {
    if (timeTillNext > 0) return;

    timeTillNext = COOL_DOWN;

    auto magicball = std::make_unique<Magicball>(caster->getPos(), dir, caster->getAllyOrEnemy());
    GameController::getInstance()->projectileHandler.add(std::move(magicball));
}
