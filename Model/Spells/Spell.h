#pragma once


#include "../Characters/Character.h"

class Spell {
protected:
    Character* caster;
    float COOL_DOWN;
    float timeTillNext;
    std::string name;
public:
    Spell(Character* character, float coolDown, std::string name = ""): caster(character), COOL_DOWN(coolDown),
    name(name), timeTillNext(0){};
    virtual void cast(sf::Vector2f={}) = 0;
    void updateTimeTillNext(float time);

    float getTimeTillNext();
    float getCoolDown();
    void setCoolDown(float t);

    std::string getName();
};


