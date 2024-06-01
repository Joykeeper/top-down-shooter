//
// Created by Admin on 02.05.2024.
//

#include <iostream>
#include "Player.h"

int Player::getShieldPoints() const {
    return this->shieldPoints;
}


void Player::setShieldPoints(int shP) {
    this->shieldPoints = shP;

    if (shieldPoints <= 0){
        this->shieldPoints = 0;
    }

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
        health_ = hp;
    }
}
