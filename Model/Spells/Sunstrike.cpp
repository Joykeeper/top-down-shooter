//
// Created by Admin on 08.06.2024.
//

#include "Sunstrike.h"
#include "../../GameController.h"
#include "../Auras/WarningAura.h"
#include "../Auras/BurningAura.h"

void Sunstrike::cast(sf::Vector2f pos) {
    timeTillNext = COOL_DOWN;

    //auto playerPos = GameController::getInstance()->player.getPos();

    auto explosion = std::make_unique<BurningAura>(pos, sunstrikeRadius, 0.1, COOL_DOWN,
                                                  caster, caster->getAllyOrEnemy(), 100);

//    if (!explosion->getTexture().loadFromFile("assets/sunstrikeEffect.png"))
//    {
//        std::cout << "Couldn't load image";
//    }
//
//    explosion->getSprite().setTexture(explosion->getTexture());
//    explosion->getSprite().setColor(sf::Color(255, 255, 255, 128));
//    explosion->getSprite().setTextureRect(sf::IntRect(128, 0, 64, 64));
//    explosion->getSprite().setScale(explosion->getRadius()/32, explosion->getRadius()/32);


    auto sunstrikeTexture = sf::Texture();
    if (!sunstrikeTexture.loadFromFile("assets/sunstrikeEffect.png"))
    {
        std::cout << "Couldn't load image";
    }


    explosion->getAnimationHandler() = AnimationHandler(sunstrikeTexture, sf::Vector2i (64, 64),
                                              sf::Vector2f (explosion->getRadius()/32, explosion->getRadius()/32), 1);

    explosion->getAnimationHandler().createAnimation("default", std::pair<sf::Vector2i,sf::Vector2i>(
            sf::Vector2i(0,0),
            sf::Vector2i(5, 0))
    );

    explosion->getAnimationHandler().setAnimation("default");


    auto sunstrike = std::make_unique<WarningAura>(pos, sunstrikeRadius, 1.5, COOL_DOWN,
                                                   caster, caster->getAllyOrEnemy(), std::move(explosion));



    GameController::getInstance()->auraHandler.add(std::move(sunstrike));
}
