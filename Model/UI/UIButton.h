#pragma once

#include "SFML/Graphics.hpp"
#include "ButtonCommands/ButtonCommand.h"
#include <memory>

class UIButton {
    sf::Vector2f position_;
    sf::Vector2f size_;

    std::string text_;
    int fontSize_;
    sf::Color fontColor_;

    sf::Color bgColorIdle_;
    sf::Color bgColorSelected_;

    std::unique_ptr<ButtonCommand> command;

    bool selected;

public:
    UIButton(sf::Vector2f position, std::string text, int fontSize = 16, sf::Vector2f size={100, 100},
             sf::Color fontColor=sf::Color::Black, sf::Color bgColorIdle=sf::Color::White,
             sf::Color bgColorSelected=sf::Color::Yellow):position_(position),
             text_(text), size_(size), fontSize_(fontSize), fontColor_(fontColor), bgColorIdle_(bgColorIdle),
             bgColorSelected_(bgColorSelected){};

    sf::Vector2f getPosition() const;
    sf::Vector2f getSize() const;

    std::string getText() const;
    int getTextLength() const;
    sf::Color getFontColor() const;
    int getFontSize() const;

    sf::Color getIdleBg() const;
    sf::Color getSelectedBg() const;

    bool isSelected() const;
    void setSelected(bool);

    void click(){
        if (!command) return;
        command->fire();
    }

    void setCommand(std::unique_ptr<ButtonCommand> buttonCommand);

};
