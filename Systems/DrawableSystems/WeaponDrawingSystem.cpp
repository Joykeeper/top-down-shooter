//
// Created by Admin on 05.05.2024.
//

#include "WeaponDrawingSystem.h"
#include "../../GameController.h"

auto drawWeapons(auto characters, sf::RenderWindow& window) -> void;

void WeaponDrawingSystem::draw(sf::RenderWindow &window) const {
    auto characters = GameController::getInstance()->getCharacters();

    drawWeapons(characters, window);
}

void drawWeapons(auto characters, sf::RenderWindow& window){
    for(auto& ch: characters){
        if (ch->hasWeapon()) {
            sf::RectangleShape weaponSprite(ch->getWeapon()->getSize());
            auto weaponPos = ch->getWeapon()->getPos();
            weaponSprite.setPosition(weaponPos-ch->getWeapon()->getSize()/2.f);
            weaponSprite.setFillColor(sf::Color::Red);
            window.draw(weaponSprite);
        }
    }
}