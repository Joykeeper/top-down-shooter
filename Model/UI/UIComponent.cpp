//
// Created by Admin on 09.09.2024.
//

#include <iostream>
#include "UIComponent.h"

sf::Color UIComponent::getColor() {
    return sf::Color();
}

sf::Vector2f UIComponent::getPos() {
    return sf::Vector2f();
}

UIComponent::UIComponent(sf::Vector2f position, sf::Vector2f size, sf::Vector2f spriteScale,
                         const sf::Texture& texture, sf::Vector2f spritesPositionInTexture,
                         sf::Vector2i spriteSize): position_(position),
                                               texture_(texture), spriteSize_(spriteSize),
                                               spritesPositionInTexture_(spritesPositionInTexture),
                                               spriteScale_(spriteScale), size_(size){
    withTexture = true;
}

UIComponent::UIComponent(sf::Vector2f position, sf::Vector2f size, sf::Color &color): position_(position),
                                               color_(color), size_(size){
    withTexture = false;
}

void UIComponent::setTexture(sf::Texture t) {
    this->texture_ = t;
}

sf::Vector2f UIComponent::getSize() {
    return size_;
}

sf::Sprite& UIComponent::getSprite() {
    sprite_.setTexture(this->texture_);
    sprite_.setTextureRect(sf::IntRect (spritesPositionInTexture_.x*spriteSize_.x,
                                        spritesPositionInTexture_.y*spriteSize_.y,
                                        spriteSize_.x,
                                        spriteSize_.y));
    sprite_.setScale(spriteScale_);
    sprite_.setPosition(this->position_);
    return sprite_;
}

bool UIComponent::hasTexture() const {
    return withTexture;
}

sf::Texture UIComponent::getTexture() {
    return texture_;
}
