//
// Created by Admin on 16.06.2024.
//

#include "TraceLeavingEffect.h"
#include "../Characters/Character.h"
#include "../Auras/BurningAura.h"
#include "../../GameController.h"

void TraceLeavingEffect::effect(Character &c, float deltaTime) {
    this->Effect::effect(c);

    if (timeTillTrace <= 0){

        auto trace = std::make_unique<BurningAura>(c.getPos(), radius, 2, 0.3,
                                                  &c, c.getAllyOrEnemy(), 1);


        auto texture = sf::Texture();
        if (!texture.loadFromFile("assets/fireStepsEffect.png"))
        {
            std::cout << "Couldn't load image";
        }
        trace->getAnimationHandler().setSpriteSheet(texture);
//        trace->getSprite().setTexture(trace->getTexture());
//        trace->getSprite().setColor(sf::Color(255, 255, 255, 128));
//        trace->getSprite().setTextureRect(sf::IntRect(0, 0, 32, 32));
//        trace->getSprite().setScale(trace->getRadius()/16, trace->getRadius()/16);
        trace->getAnimationHandler().getCurrentSprite().setColor(sf::Color(255, 255, 255, 128));
        trace->getAnimationHandler().setSpriteScale(sf::Vector2f(trace->getRadius()/16, trace->getRadius()/16));
        trace->getAnimationHandler().setSpriteSize(sf::Vector2i (32, 32));

        GameController::getInstance()->auraHandler.add(std::move(trace));


        timeTillTrace = FREQUENCY;

    } else{
        timeTillTrace -= deltaTime;
    }
}
