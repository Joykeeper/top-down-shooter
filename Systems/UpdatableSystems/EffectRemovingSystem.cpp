//
// Created by Admin on 17.05.2024.
//

#include "EffectRemovingSystem.h"
#include "../../GameController.h"
#include "../../Model/Effects/Effect.h"


void EffectRemovingSystem::update(sf::Time dt) const {
    auto characters = GameController::getInstance()->getCharacters();

    for(Character* character: characters){
        for (auto &effect: character->getEffects()){
            effect->uneffect(*character);

            effect->setTimeLeft(effect->getTimeLeft()-dt.asSeconds());
        }
    }
    for(Character* character: characters){
        for (auto &effect: character->getEffects()){
            if (effect->getTimeLeft() <= 0){
                character->removeEffect(*effect);
            }
        }
    }
}
