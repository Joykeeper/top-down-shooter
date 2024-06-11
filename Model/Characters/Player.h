#pragma once
#include "SFML/Graphics.hpp"
#include "Character.h"

class Spell;

class Player : public Character{
    int shieldPoints;
    std::unique_ptr<Weapon> weapon;

    std::unique_ptr<Spell> activeSkill1;
    std::unique_ptr<Spell> activeSkill2;

    std::unique_ptr<Effect> passiveSkill1;
    std::unique_ptr<Effect> passiveSkill2;

public:
    Player(std::unique_ptr<Weapon> weapon = nullptr);

    ~Player() override = default;

    int getShieldPoints() const;

    void setHealth(int);

    bool hasWeapon();


    void setWeapon(std::unique_ptr<Weapon> weapon1);

    std::unique_ptr<Magicball> shoot(sf::Vector2f dir);

    Weapon& getWeapon();

    void move(sf::Vector2f vec);

    Spell* getActiveSkill1();
    Spell* getActiveSkill2();


    Effect* getPassiveSkill1();
    Effect* getPassiveSkill2();

    void setActiveSkill1(std::unique_ptr<Spell> spell);
    void setActiveSkill2(std::unique_ptr<Spell> spell);

    void setPassiveSkill1(std::unique_ptr<Effect> effect);
    void setPassiveSkill2(std::unique_ptr<Effect> effect);

    void setShieldPoints(int);

    void setPosition(sf::Vector2f pos);
};

