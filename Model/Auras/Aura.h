#pragma once

#include "../GameObject.h"
#include "../Effects/Effect.h"
#include "../AllyOrEnemy.h"

class Aura{
    sf::Vector2f position_;
    float radius;
    Character* creator;
    AllyOrEnemy allyOrEnemy;
    std::vector<Effect> providingEffects;
    float EFFECT_COOL_DOWN;
    float timeTillNextEffect;
    float lifeTime;
public:
    Aura(sf::Vector2f pos, float radius, float lifetime, float cooldown, Character* creator, AllyOrEnemy allyOrEnemy):
    position_(pos), radius(radius), lifeTime(lifetime), creator(creator),
    EFFECT_COOL_DOWN(cooldown), timeTillNextEffect(0), allyOrEnemy(allyOrEnemy){};

    sf::Vector2f getPosition() const;

    float getRadius() const;

    float getLifeTime();
    void setLifeTime(float);

    Character* getCreator();

    AllyOrEnemy getAllyOrEnemy() const;

    float getCoolDown() const;

    float getTimeTillNextEffect();
    void setTimeTillNextEffect(float t);
    void resetTimeTillNextEffect();

    virtual void applyEffect(Character& character) = 0;
};

