//
// Created by Admin on 15.06.2024.
//

#include "UILabel.h"

std::string UILabel::getText() {
    return content_;
}

int UILabel::getFontSize() {
    return fontSize_;
}

sf::Color UILabel::getFontColor() {
    return fontColor_;
}

sf::Vector2f UILabel::getPosition() {
    return  position_;
}
