# pragma once

#include "SFML/Graphics.hpp"

class AnimationHandler {
    sf::Texture spriteSheet;

    sf::Sprite currentSprite;

    int lengthOfFrame;

    std::map<std::string, std::pair<sf::Vector2i,sf::Vector2i>> animations;

    std::string currentAnimation;

    int currentIndexOfSpriteInAnimation;  // number of sprite relatively to its animation

    int frameCount; // uses length of frame

    sf::Vector2i spriteSize;

    sf::Vector2f spriteScale;

public:
    AnimationHandler(): spriteSheet(sf::Texture()), lengthOfFrame(0),
    spriteSize(sf::Vector2i (16, 16)), spriteScale(sf::Vector2f (4, 4)),
                        currentIndexOfSpriteInAnimation(0), frameCount(0){};
    AnimationHandler(sf::Texture spriteSheet, sf::Vector2i spriteSize,
                     sf::Vector2f spriteScale, int lengthOfFrame);

    void setSpriteSheet(sf::Texture spriteSheet);

    void setLengthOfFrame(int lengthOfFrame);

    const sf::Vector2f &getSpriteScale() const;

    void setSpriteScale(const sf::Vector2f &spriteScale);

    void setSpriteSize(const sf::Vector2i &spriteSize);

    const sf::Vector2i &getSpriteSize() const;

    sf::Sprite& getCurrentSprite();

    void setAnimation(std::string);

    void createAnimation(std::string, std::pair<sf::Vector2i, sf::Vector2i>);

    void nextFrame();

};

