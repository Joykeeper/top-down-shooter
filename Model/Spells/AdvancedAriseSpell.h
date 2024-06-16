#pragma once


#include "Spell.h"

class AdvancedAriseSpell : public Spell{
public:
    AdvancedAriseSpell(Character* character) : Spell(character, 15, "Advanced Arise"){};
    void cast(sf::Vector2f={}) override;
};

