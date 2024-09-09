#pragma once

#include "SFML/Graphics.hpp"
#include "ButtonCommands/ButtonCommand.h"
#include <memory>
#include <iostream>

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

    sf::Texture texture_;

    sf::Sprite defaultSprite_;
    sf::Sprite hoveredSprite_;
public:
    UIButton(sf::Vector2f position, std::string text, int fontSize = 16, sf::Vector2f size={100, 100},
             sf::Color fontColor=sf::Color::Black, sf::Color bgColorIdle=sf::Color::White,
             sf::Color bgColorSelected=sf::Color::Yellow):position_(position),
             text_(text), size_(size), fontSize_(fontSize), fontColor_(fontColor), bgColorIdle_(bgColorIdle),
             bgColorSelected_(bgColorSelected){
        if (!this->texture_.loadFromFile("assets/buttons_extended.png"))
        {
            std::cout << "Couldn't load image";
        }

        this->defaultSprite_.setTexture(this->texture_);
        this->hoveredSprite_.setTexture(this->texture_);

        this->defaultSprite_.setTextureRect(sf::IntRect(
                192,
                0,
                96,
                64));

        this->hoveredSprite_.setTextureRect(sf::IntRect(
                192,
                64,
                96,
                64));
    };

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

    sf::Texture &getTexture();

    sf::Sprite &getDefaultSprite();
    sf::Sprite &getHoveredSprite();

    void setTexture(sf::Texture);

    void setDefaultSprite(sf::Sprite);
    void setHoveredSprite(sf::Sprite);

};
