//
// Created by Admin on 08.06.2024.
//

#include "SpellHandlingSystem.h"
#include "../../GameController.h"

void SpellHandlingSystem::update(sf::Time dt) const {
    auto& enemies = GameController::getInstance()->enemyHandler.getItems();

    for (auto& enemy: enemies){
        enemy->getSpell().updateTimeTillNext(dt.asSeconds());
    }
}
