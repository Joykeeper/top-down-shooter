#pragma once
#include "SFML/Graphics.hpp"
#include "GameObject.h"
#include "Effects/Effect.h"
#include "AllyOrEnemy.h"
#include "Effects/AttackSpeedEffect.h"
#include <memory>

class Magicball : public GameObject{
    float speed;
    float lifeTime;
    int damage;
    AllyOrEnemy allyOrEnemy;

    sf::Vector2f direction;

    std::vector<std::unique_ptr<Effect>> characterEffects;

public:
    Magicball(sf::Vector2f startPos, sf::Vector2f dir, AllyOrEnemy type) :
            GameObject(startPos, {40, 40}),  speed(1000), lifeTime(3), direction(dir), damage(1),
            allyOrEnemy(type){
        this->addEffect(std::make_unique<AttackSpeedEffect>(0.3, 5));
    };

    sf::Vector2f getDirection();
    float getSpeed();
    float getLifeTime();
    void setLifeTime(float);
    void setDirection(sf::Vector2f);

    void addEffect(std::unique_ptr<Effect> effect);
    void removeEffect(const Effect& effect);
    std::vector<std::unique_ptr<Effect>>& getEffects();

    int getDamage();
    AllyOrEnemy getAllyOrEnemy() const;
};



