//
// Created by Admin on 05.05.2024.
//

#include <iostream>
#include "WeaponHandlingSystem.h"
#include "../../GameController.h"

auto updateWeapons(const std::vector<Character*>& characters, sf::Time dt) -> void;

void WeaponHandlingSystem::update(sf::Time dt) const {
    auto characters = GameController::getInstance()->getCharacters();

    updateWeapons(characters, dt);
}

void updateWeapons(const std::vector<Character*>& characters, sf::Time dt){
    for(auto character: characters){
        if (character->hasWeapon()){
            auto weapon = character->getWeapon();

            std::cout << weapon->getPos().x << " " << weapon->getPos().y << "weapon pos \n";

            if (weapon->getTimeFromLastShot() < weapon->getShootingCooldown()){
                weapon->setTimeFromLastShot(weapon->getTimeFromLastShot()+dt.asSeconds());
            }
        }
    }
}