#pragma once


#include "../Characters/Character.h"

class Spell {
protected:
    Character* caster;
    float COOL_DOWN;
    float timeTillNext;
public:
    Spell(Character* character, float coolDown): caster(character), COOL_DOWN(coolDown),
    timeTillNext(0){};
    virtual void cast(sf::Vector2f={}) = 0;
    void updateTimeTillNext(float time);

    float getTimeTillNext();
};


