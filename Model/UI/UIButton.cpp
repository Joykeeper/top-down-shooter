//
// Created by Admin on 09.06.2024.
//

#include "UIButton.h"

sf::Vector2f UIButton::getPosition() const {
    return position_;
}

sf::Vector2f UIButton::getSize() const {
    return size_;
}

std::string UIButton::getText() const {
    return text_;
}

sf::Color UIButton::getFontColor() const {
    return fontColor_;
}

sf::Color UIButton::getIdleBg() const {
    return bgColorIdle_;
}

sf::Color UIButton::getSelectedBg() const {
    return bgColorSelected_;
}

bool UIButton::isSelected() const {
    return selected;
}

void UIButton::setSelected(bool s) {
    selected = s;
}

void UIButton::setCommand(std::unique_ptr<ButtonCommand> buttonCommand) {
    command = std::move(buttonCommand);
}

int UIButton::getTextLength() const {
    return text_.length();
}

int UIButton::getFontSize() const {
    return fontSize_;
}

