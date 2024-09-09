#pragma once
#include "SFML/Graphics.hpp"
#include "Character.h"
#include "../AnimationHandler.h"

class Spell;

class Player : public Character{
    int shieldPoints;

    std::unique_ptr<Spell> defaultAttack;

    std::unique_ptr<Spell> activeSkill1;
    std::unique_ptr<Spell> activeSkill2;


    std::map<int, int> levelBreakThroughLimits;

    int enemyKillCount;

    int powerLevel;

    WeaponType weaponType;

public:

    Player(WeaponType weaponType = WeaponType::FIRE_STAFF);

    ~Player() override = default;

    int getShieldPoints() const;

    void setHealth(int);

    WeaponType getWeaponType() const;
    void setWeaponType(WeaponType);

    void move(sf::Vector2f vec);

    Spell* getDefaultAttack();
    std::unique_ptr<Spell> provideDefaultAttack();
    void setDefaultAttack(std::unique_ptr<Spell> spell);

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

    int getEnemyKillCount() const;
    void enemyKilled();

    std::map<int, int> getLevelBreakThroughLimits() const;

    int getPowerLevel() const;

    void levelUp();

    void resetSelf();

};

