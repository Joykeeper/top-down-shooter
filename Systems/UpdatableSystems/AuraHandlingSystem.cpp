//
// Created by Admin on 06.06.2024.
//

#include "AuraHandlingSystem.h"
#include "../../GameController.h"
#include "../../Utils.h"

auto checkLifeTime(sf::Time dt) -> void ;

void AuraHandlingSystem::update(sf::Time dt) const {
    auto& auras = GameController::getInstance()->auraHandler.getItems();
    auto characters = GameController::getInstance()->getCharacters();
    auto& projectiles = GameController::getInstance()->projectileHandler.getItems();

    checkLifeTime(dt);

    for (auto& aura: auras){
        if (aura->getTimeTillNextEffect() <= 0){
            for (auto& character: characters){
                if (Utils::objectInRadius(*character, aura->getRadius(), aura->getPosition())){
                    aura->applyEffect(*character);
                }
            }
            for (auto& projectile: projectiles){
                if (Utils::objectInRadius(*projectile, aura->getRadius(), aura->getPosition())){
                    aura->applyProjectileEffect(*projectile);
                }
            }
            aura->resetTimeTillNextEffect();
        } else {
            aura->setTimeTillNextEffect(aura->getTimeTillNextEffect()-dt.asSeconds());
        }
    }

    for (auto& e : GameController::getInstance()->aurasToAdd.getItems()){
        GameController::getInstance()->auraHandler.add(std::move(e));
    }

    GameController::getInstance()->aurasToAdd.clear();

}

void checkLifeTime(sf::Time dt){
    auto& auras = GameController::getInstance()->auraHandler.getItems();
    auto removedAuras = std::vector<Aura*>();

    for (auto& aura: auras){
        if (aura->getLifeTime() <= 0){
            aura->actionOnEnd();
            removedAuras.push_back(aura.get());
        } else {
            aura->setLifeTime(aura->getLifeTime()-dt.asSeconds());
        }
    }

    for (auto aura: removedAuras){
        GameController::getInstance()->auraHandler.remove(aura);
    }
}