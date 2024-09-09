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

    auto texture = sf::Texture();
    if (!texture.loadFromFile("assets/summoningEffect.png"))
    {
        std::cout << "Couldn't load image";
    }

    graveyard->getAnimationHandler() = AnimationHandler(texture, sf::Vector2i (32, 32),
                                              sf::Vector2f (graveyardRadius/16, graveyardRadius/16), 2);

    graveyard->getAnimationHandler().createAnimation("default", std::pair<sf::Vector2i,sf::Vector2i>(
            sf::Vector2i(0,0),
            sf::Vector2i(2, 0))
    );
    graveyard->getAnimationHandler().setAnimation("default");


    auto warning = std::make_unique<WarningAura>(pos, graveyardRadius, 2, COOL_DOWN,
                                                   caster, caster->getAllyOrEnemy(), std::move(graveyard));

    warning->getAnimationHandler() = AnimationHandler(texture, sf::Vector2i (32, 32),
                                                        sf::Vector2f (graveyardRadius/16, graveyardRadius/16), 8);

    warning->getAnimationHandler().createAnimation("default", std::pair<sf::Vector2i,sf::Vector2i>(
            sf::Vector2i(0,0),
            sf::Vector2i(2, 0))
    );
    warning->getAnimationHandler().setAnimation("default");


    GameController::getInstance()->aurasToAdd.add(std::move(warning));
}
