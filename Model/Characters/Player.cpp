//
// Created by Admin on 02.05.2024.
//

#include <iostream>
#include "Player.h"
#include "../Magicball.h"
#include "../Spells/Spell.h"
#include "../Spells/Sunstrike.h"
#include "../Spells/AriseSpell.h"
#include "../Spells/MSPDBuff.h"
#include "../Spells/ASPDBuff.h"
#include "../Effects/MoveSpeedEffect.h"
#include "../Spells/BallSpell.h"
#include "../Spells/BurningBallSpell.h"
#include "../Effects/BurningEffect.h"
#include "../Effects/BurningMagicBalls.h"


Player::Player(WeaponType weapon) : Character(sf::Vector2f(10, 10),
                                                           sf::Vector2f(60, 60), 10, 300, AllyOrEnemy::ALLY),
                                                 shieldPoints(10), levelBreakThroughLimits({{1,10},{2, 20}, {3,30}, {4,40}, {5,50}}),
                                                 enemyKillCount(19),
                                                 powerLevel(0), weaponType(weapon){

    defaultAttack = std::make_unique<BallSpell>(this);
}


int Player::getShieldPoints() const {
    return this->shieldPoints;
}

void Player::setShieldPoints(int shP) {
    this->shieldPoints = shP;
}

void Player::setHealth(int hp) {

    int damage = health_ - hp;

    if (damage > 0) {
        if (shieldPoints > 0) {
            int shieldDamage = std::min(damage, shieldPoints);
            setShieldPoints(shieldPoints - shieldDamage);
            damage -= shieldDamage;
        }
    }
    health_ -= damage;


    if (this->health_ < 0) this->health_ = 0;
    if (this->health_ > MAX_HEALTH) this->health_ = MAX_HEALTH;
}

WeaponType Player::getWeaponType() const{
    return weaponType;
}

void Player::move(sf::Vector2f vec) {
    this->position_ += vec;
}

void Player::setPosition(sf::Vector2f pos) {
    position_ = pos;
}

Spell* Player::getActiveSkill1() {
    return activeSkill1.get();
}

Spell* Player::getActiveSkill2() {
    return activeSkill2.get();
}

Effect* Player::getPassiveSkill1() {
    for (auto& effect: effects){
        if (effect->isPassive()){
            return effect.get();
        }
    }
    return nullptr;
}

Effect* Player::getPassiveSkill2() {
    if (getPassiveSkill1()){
        auto count = 0;
        for (auto& effect: effects){
            if (effect->isPassive()){
                count++;
                if (count == 2){
                    return effect.get();
                }
            }
        }
    }
    return nullptr;
}

void Player::setActiveSkill1(std::unique_ptr<Spell> spell) {
    activeSkill1 = std::move(spell);
}

void Player::setActiveSkill2(std::unique_ptr<Spell> spell) {
    activeSkill2 = std::move(spell);
}

void Player::setPassiveSkill1(std::unique_ptr<Effect> effect) {
    effect->setPassive(true);

    if (!getPassiveSkill1()) {
        addEffect(std::move(effect));
        return;
    } else if (getPassiveSkill2()){
        getPassiveSkill1()->setTimeLeft(0);
    }

    addEffect(std::move(effect));
}

void Player::setPassiveSkill2(std::unique_ptr<Effect> effect) {
    effect->setPassive(true);

    if (!getPassiveSkill2()) {
        addEffect(std::move(effect));
        return;
    }
    getPassiveSkill2()->setTimeLeft(0);

    addEffect(std::move(effect));
}

int Player::getEnemyKillCount() const {
    return enemyKillCount;
}

void Player::enemyKilled() {
    enemyKillCount++;
}

std::map<int, int> Player::getLevelBreakThroughLimits() const {
    return levelBreakThroughLimits;
}

void Player::levelUp() {
    powerLevel++;
}

int Player::getPowerLevel() const{
    return powerLevel;
}

Spell *Player::getDefaultAttack() {
    return defaultAttack.get();
}

void Player::setDefaultAttack(std::unique_ptr<Spell> spell) {
    defaultAttack = std::move(spell);
}

std::unique_ptr<Spell> Player::provideDefaultAttack() {
    return std::move(defaultAttack);
}

void Player::setWeaponType(WeaponType type) {
    weaponType = type;
}

void Player::resetSelf() {
    health_ = 10;
    shieldPoints = 10;
    effects.clear();
    enemyKillCount = 0;
    powerLevel = 0;
    setActiveSkill1(nullptr);
    setActiveSkill2(nullptr);
}

