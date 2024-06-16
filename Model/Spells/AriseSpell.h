#pragma once


#include "Spell.h"

class AriseSpell : public Spell{
public:
    AriseSpell(Character* character, float radius=200) : Spell(character, 4, "Arise"){};
    void cast(sf::Vector2f={}) override;
};

