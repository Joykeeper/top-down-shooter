#pragma once

#include <string>
#include "SFML/Graphics.hpp"

class UILabel {

    sf::Vector2f position_;

    std::string content_;
    int fontSize_;
    sf::Color fontColor_;

public:
    UILabel(sf::Vector2f pos, std::string text, int fontSize=10, sf::Color color=sf::Color::Black):
    position_(pos), content_(text), fontSize_(fontSize), fontColor_(color){};

    sf::Vector2f getPosition();

    std::string getText();

    int getFontSize();

    sf::Color getFontColor();
};

