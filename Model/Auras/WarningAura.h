#pragma once

#include "Aura.h"
#include "../Spells/Spell.h"

class WarningAura : public Aura {
    std::unique_ptr<Aura> auraToPut;

public:
    WarningAura(sf::Vector2f position, float radius, float lifeTime, float cooldown, Character* creator, AllyOrEnemy allyOrEnemy, std::unique_ptr<Aura> aura)
    : Aura(position, radius, lifeTime, cooldown, creator, allyOrEnemy, sf::Color::White), auraToPut(std::move(aura)){
//        if (!this->getTexture().loadFromFile("assets/warningEffect.png"))
//        {
//            std::cout << "Couldn't load image";
//        }
//
//        this->getSprite().setTexture(this->getTexture());
//        this->getSprite().setColor(sf::Color(255, 255, 255, 128));
//        this->getSprite().setTextureRect(sf::IntRect(0, 0, 64, 64));
//        this->getSprite().setScale(radius/32, radius/32);

        auto texture = sf::Texture();
        if (!texture.loadFromFile("assets/warningEffect.png"))
        {
            std::cout << "Couldn't load image";
        }

        this->animationHandler = AnimationHandler(texture, sf::Vector2i (64, 64),
                                                  sf::Vector2f (radius/32, radius/32), 4);

        // creating animations
        this->animationHandler.createAnimation("default", std::pair<sf::Vector2i,sf::Vector2i>(
                sf::Vector2i(0,0),
                sf::Vector2i(3, 0))
        );

        this->animationHandler.setAnimation("default");
    }

    void applyEffect(Character&) override { };
    void applyProjectileEffect(Magicball&) override { };
    void actionOnEnd() override;

};

