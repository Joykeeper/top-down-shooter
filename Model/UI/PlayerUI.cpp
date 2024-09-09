//
// Created by Admin on 09.09.2024.
//

#include <iostream>
#include "PlayerUI.h"

PlayerUI::PlayerUI() {

    sf::Texture infoTexture;
    if (!infoTexture.loadFromFile("assets/buttons_extended.png"))
    {
        std::cout << "Couldn't load image";
    }

    infoBlock = std::make_unique<UIComponent>(
            sf::Vector2f(1300, 500), sf::Vector2f(250, 200),
            sf::Vector2f(250.f/96, 200.f/64),infoTexture,
            sf::Vector2f(2, 1), sf::Vector2i(96, 64)
            );

    activeSkillsBlock = std::make_unique<UIComponent>(
            sf::Vector2f(55, 445), sf::Vector2f(150, 120),
            sf::Vector2f(150.f/96, 120.f/64),infoTexture,
            sf::Vector2f(0, 1), sf::Vector2i(96, 64)
            );

    passiveSkillsBlock = std::make_unique<UIComponent>(
            sf::Vector2f(20, 160), sf::Vector2f(240, 170),
            sf::Vector2f(240.f/96, 130.f/64),infoTexture,
            sf::Vector2f(1, 1), sf::Vector2i(96, 64)
    );


}
