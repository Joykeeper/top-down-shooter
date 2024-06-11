//
// Created by Admin on 02.05.2024.
//

#include <iostream>
#include "Player.h"
#include "../Magicball.h"
#include "../Spells/Spell.h"
#include "../Spells/Sunstrike.h"
#include "../Spells/AriseSpell.h"

int Player::getShieldPoints() const {
    return this->shieldPoints;
}


void Player::setShieldPoints(int shP) {
    this->shieldPoints = shP > 0? shP: 0;
}

void Player::setHealth(int hp) {

    int diff = health_ - hp;
    if (diff > 0 && shieldPoints > 0){
        if (shieldPoints - diff < 0){
            this->health_ -= diff + shieldPoints;
            setShieldPoints(shieldPoints);
        } else{
            setShieldPoints(shieldPoints-diff);
        }
    } else{
        health_ = hp > 0? hp: 0;
    }
}

bool Player::hasWeapon() {
    return weapon != nullptr;
}

std::unique_ptr<Magicball> Player::shoot(sf::Vector2f dir) {
    if(hasWeapon()){
        return std::move(this->weapon->shootProjectile(dir));
    }
    return nullptr;
}

void Player::setWeapon(std::unique_ptr<Weapon> weapon1) {
    this->weapon = std::move(weapon1);
}

Weapon& Player::getWeapon() {
    if (this->weapon){
        return *weapon;
    } else{
        throw std::runtime_error("Player does not have a weapon");
    }
}

void Player::move(sf::Vector2f vec) {
    this->position_ += vec;
    if (this->hasWeapon()){
        this->weapon->move(vec);
    }
}

void Player::setPosition(sf::Vector2f pos) {
    this->weapon->move(pos - position_);
    position_ = pos;
}

Player::Player(std::unique_ptr<Weapon> weapon) : Character(sf::Vector2f(10, 10),
                                                           sf::Vector2f(60, 60), 50, 300, AllyOrEnemy::ALLY),
                                                 weapon(std::move(weapon)),
                                                 shieldPoints(40){
    setActiveSkill1(std::make_unique<Sunstrike>(this, 100));
    setActiveSkill2(std::make_unique<AriseSpell>(this, 20));
}

Spell* Player::getActiveSkill1() {
    return activeSkill1.get();
}

Spell* Player::getActiveSkill2() {
    return activeSkill2.get();
}

Effect* Player::getPassiveSkill1() {
    return passiveSkill1.get();
}

Effect* Player::getPassiveSkill2() {
    return passiveSkill2.get();
}

void Player::setActiveSkill1(std::unique_ptr<Spell> spell) {
    activeSkill1 = std::move(spell);
}

void Player::setActiveSkill2(std::unique_ptr<Spell> spell) {
    activeSkill2 = std::move(spell);
}

void Player::setPassiveSkill1(std::unique_ptr<Effect> effect) {
    passiveSkill1 = std::move(effect);
}

void Player::setPassiveSkill2(std::unique_ptr<Effect> effect) {
    passiveSkill2 = std::move(effect);
}
