//
// Created by Admin on 07.09.2024.
//

#include "AnimationHandler.h"

#include <utility>
#include <iostream>

sf::Sprite& AnimationHandler::getCurrentSprite() {

    auto startOfSpan= this->animations[currentAnimation].first;
    auto rectLeft = startOfSpan.x + this->currentIndexOfSpriteInAnimation;
    this->currentSprite.setTexture(this->spriteSheet);

    this->currentSprite.setTextureRect(sf::IntRect(
            rectLeft*spriteSize.x,
            startOfSpan.y*spriteSize.y,
            spriteSize.x,
            spriteSize.y));

    this->currentSprite.setScale(spriteScale.x, spriteScale.y);

    return this->currentSprite;
}

void AnimationHandler::setAnimation(std::string animationName) {
    if (animationName != this->currentAnimation){
        this->currentAnimation = std::move(animationName);
        this->frameCount = 0;
        this->currentIndexOfSpriteInAnimation = 0;
    }
}

void AnimationHandler::createAnimation(std::string animationName, std::pair<sf::Vector2i, sf::Vector2i> textureSpan) {
    animations[animationName] = textureSpan;
}

void AnimationHandler::nextFrame() {
    if (this->frameCount == this->lengthOfFrame - 1){

        auto currentAnimationSpan = animations[this->currentAnimation];
        auto lengthOfCurrentAnimation = currentAnimationSpan.second.x - currentAnimationSpan.first.x;
        if (this->currentIndexOfSpriteInAnimation == lengthOfCurrentAnimation){
            this->currentIndexOfSpriteInAnimation = 0;
        } else {
            this->currentIndexOfSpriteInAnimation++;
        }

        this->frameCount = 0;
    } else {
        this->frameCount++;
    }
}

const sf::Vector2i &AnimationHandler::getSpriteSize() const {
    return spriteSize;
}

void AnimationHandler::setSpriteSize(const sf::Vector2i &size) {
    this->spriteSize = size;
}

void AnimationHandler::setSpriteScale(const sf::Vector2f &scale) {
    this->spriteScale = scale;
}

const sf::Vector2f &AnimationHandler::getSpriteScale() const {
    return spriteScale;
}

void AnimationHandler::setSpriteSheet(sf::Texture sheet) {
    this->spriteSheet = sheet;
}

void AnimationHandler::setLengthOfFrame(int lOF) {
    this->lengthOfFrame = lOF;
}

AnimationHandler::AnimationHandler(sf::Texture spriteSheet, sf::Vector2i spriteSize,
                                   sf::Vector2f spriteScale = sf::Vector2f(4, 4),
                                   int lengthOfFrame = 4) : spriteSheet(
        spriteSheet), lengthOfFrame(lengthOfFrame), spriteSize(spriteSize), spriteScale(
        spriteScale), currentIndexOfSpriteInAnimation(0), frameCount(0) {}
