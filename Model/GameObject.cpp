//
// Created by Admin on 03.05.2024.
//

#include "GameObject.h"

sf::Vector2f GameObject::getPos() const{
    return this->position_;
}

void GameObject::move(sf::Vector2f vec) {
    this->position_ += vec;
}
