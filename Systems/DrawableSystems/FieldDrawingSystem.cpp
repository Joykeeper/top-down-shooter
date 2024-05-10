//
// Created by Admin on 03.05.2024.
//

#include "FieldDrawingSystem.h"

void FieldDrawingSystem::draw(sf::RenderWindow& window) const{
//    sf::Texture texture;
//    texture.loadFromFile("download.png");
//    sf::Sprite sprite;
//    sf::Vector2u size = texture.getSize();
//    sprite.setTexture(&texture);
//    sprite.setOrigin(size.x / 2, size.y / 2);
//    window.draw(sprite);

    sf::Texture texture;
    texture.loadFromFile("./../download.jpg");

    sf::Sprite sprite;
    sprite.setTexture(texture);

    sprite.setPosition(sf::Vector2f(100,100));
    window.draw(sprite);
}
