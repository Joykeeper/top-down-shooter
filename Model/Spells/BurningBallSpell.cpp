//
// Created by Admin on 16.06.2024.
//

#include "BurningBallSpell.h"
#include "../../GameController.h"
#include "../Effects/BurningEffect.h"

void BurningBallSpell::cast(sf::Vector2f dir) {
    if (timeTillNext > 0) return;

    timeTillNext = COOL_DOWN;

    auto magicball = std::make_unique<Magicball>(caster->getPos(), dir, caster->getAllyOrEnemy());
    magicball->addEffect(std::make_unique<BurningEffect>(1, 1, 5));
    GameController::getInstance()->projectileHandler.add(std::move(magicball));

}
