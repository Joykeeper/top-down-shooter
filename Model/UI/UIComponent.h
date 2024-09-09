#pragma once

#include "SFML/Graphics.hpp"

class UIComponent {
protected:
    sf::Vector2f position_;

    sf::Vector2f size_;

    sf::Vector2f spriteScale_;

    sf::Color color_;

    sf::Texture texture_;
    sf::Vector2f spritesPositionInTexture_;

    sf::Sprite sprite_;
    sf::Vector2i spriteSize_;

    bool withTexture;
public:
    UIComponent(sf::Vector2f position, sf::Vector2f size, sf::Vector2f spriteScale, const sf::Texture& texture,
                sf::Vector2f spritesPositionInTexture, sf::Vector2i spriteSize);

    UIComponent(sf::Vector2f position, sf::Vector2f size, sf::Color &color);

    sf::Color getColor();

    sf::Vector2f getPos();

    sf::Vector2f getSize();

    sf::Sprite& getSprite();

    sf::Texture getTexture();

    void setTexture(sf::Texture);

    bool hasTexture() const;
};
