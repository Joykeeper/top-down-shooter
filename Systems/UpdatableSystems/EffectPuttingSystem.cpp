//
// Created by Admin on 17.05.2024.
//

#include "EffectPuttingSystem.h"
#include "../../GameController.h"
#include "../../Model/Effects/Effect.h"

void EffectPuttingSystem::update(sf::Time dt) const {
    auto characters = GameController::getInstance()->getCharacters();

    for (auto c: characters){
        auto effects = &c->getEffects();
        for (auto& effect: *effects){
            effect->effect(*c, dt.asSeconds());
        }
    }
}
