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

sf::Vector2f GameObject::getSize() const {
    return this->size_;
}

sf::Texture& GameObject::getTexture() {
    return this->texture_;
}

sf::Sprite &GameObject::getSprite() {
    return this->sprite_;
}
