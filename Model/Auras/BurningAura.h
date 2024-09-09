#pragma once


#include "Aura.h"

class BurningAura : public Aura {
    int damagePerTime;

public:
    BurningAura(sf::Vector2f position, float radius, float lifeTime, float cooldown, Character* creator, AllyOrEnemy allyOrEnemy, int damagePerTime)
            : Aura(position, radius, lifeTime, cooldown, creator, allyOrEnemy, sf::Color::Red), damagePerTime(damagePerTime) {

//        if (!this->getTexture().loadFromFile("assets/fireEffect.png"))
//        {
//            std::cout << "Couldn't load image";
//        }
//
//        this->getSprite().setTexture(this->getTexture());
//        //this->getSprite().setColor(sf::Color(255, 255, 255, 128));
//        this->getSprite().setTextureRect(sf::IntRect(0, 0, 32, 32));


        auto texture = sf::Texture();
        if (!texture.loadFromFile("assets/fireEffect.png"))
        {
            std::cout << "Couldn't load image";
        }

        this->animationHandler = AnimationHandler(texture, sf::Vector2i (32, 32),
                                                  sf::Vector2f (radius/16, radius/16), 4);

        // creating animations
        this->animationHandler.createAnimation("default", std::pair<sf::Vector2i,sf::Vector2i>(
                sf::Vector2i(0,0),
                sf::Vector2i(3, 0))
        );

        this->animationHandler.setAnimation("default");
    }

    void applyEffect(Character&) override;
    void applyProjectileEffect(Magicball&) override { };
    void actionOnEnd() override { };

};
