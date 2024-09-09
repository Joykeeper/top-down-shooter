#pragma once

#include "../GameObject.h"
#include "../Effects/Effect.h"
#include "../AllyOrEnemy.h"
#include "../Magicball.h"

class Aura{
    sf::Vector2f position_;
    float radius;
    Character* creator;
    AllyOrEnemy allyOrEnemy;
    std::vector<Effect> providingEffects;
    float EFFECT_COOL_DOWN;
    float timeTillNextEffect;
    float lifeTime;

    sf::Color color_;

protected:
    AnimationHandler animationHandler;
public:
    Aura(sf::Vector2f pos, float radius, float lifetime, float cooldown, Character* creator, AllyOrEnemy allyOrEnemy, sf::Color color):
    position_(pos), radius(radius), lifeTime(lifetime), creator(creator),
    EFFECT_COOL_DOWN(cooldown), timeTillNextEffect(0), allyOrEnemy(allyOrEnemy), color_(color){

//        sf::Texture texture;
//        if (!texture.loadFromFile("assets/fireEffect.png"))
//        {
//            std::cout << "Couldn't load image";
//        }
//
//        this->animationHandler = AnimationHandler(texture, sf::Vector2i (32, 32),
//                                                  sf::Vector2f (radius/16, radius/16), 2);
//
//        // creating animations
//        this->animationHandler.createAnimation("default", std::pair<sf::Vector2i,sf::Vector2i>(
//                sf::Vector2i(0,0),
//                sf::Vector2i(3, 0))
//        );
//
//        this->animationHandler.setAnimation("default");
    };

    sf::Vector2f getPosition() const;

    float getRadius() const;

    float getLifeTime();
    void setLifeTime(float);

    Character& getCreator();

    AllyOrEnemy getAllyOrEnemy() const;

    float getCoolDown() const;

    float getTimeTillNextEffect();
    void setTimeTillNextEffect(float t);
    void resetTimeTillNextEffect();

    sf::Color getColor() const;

    virtual void applyEffect(Character& ) = 0;
    virtual void applyProjectileEffect(Magicball& ) = 0;
    virtual void actionOnEnd() = 0;

    AnimationHandler& getAnimationHandler();
};

