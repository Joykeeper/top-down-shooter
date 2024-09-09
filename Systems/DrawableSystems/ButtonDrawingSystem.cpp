//
// Created by Admin on 09.06.2024.
//

#include "ButtonDrawingSystem.h"
#include "../../GameController.h"

void ButtonDrawingSystem::draw(sf::RenderWindow &window) const {
    auto& buttons = GameController::getInstance()->buttonHandler.getItems();

//    for (auto& button: buttons){
//        sf::RectangleShape rectangle(button->getSize());
//        if (button->isSelected()){
//            rectangle.setFillColor(button->getSelectedBg());
//            rectangle.setOutlineColor(sf::Color::Red);
//            rectangle.setOutlineThickness(5);
//        } else{
//            rectangle.setFillColor(button->getIdleBg());
//        }
//        rectangle.setPosition(button->getPosition() - button->getSize()/2.f);
//        window.draw(rectangle);
//
//
//        sf::Text text;
//        text.setFont(GameController::getInstance()->standardFont);
//
//        text.setString(button->getText());
//
//        text.setCharacterSize(button->getFontSize());
//
//        text.setPosition(sf::Vector2f(button->getPosition().x - text.getLocalBounds().width/2,button->getPosition().y -text.getLocalBounds().height/2));
//
//
//        text.setFillColor(sf::Color::Red);
//
//        //text.setStyle(sf::Text::Bold | sf::Text::Underlined);
//
//        window.draw(text);
//    }

    for (auto& button: buttons){

        auto buttonSprite = button->getDefaultSprite();

        if (button->isSelected()){
            buttonSprite = button->getHoveredSprite();
        }

        buttonSprite.setPosition(button->getPosition() - button->getSize()/2.f);
        buttonSprite.setScale(button->getSize().x/96, button->getSize().y/64);

        window.draw(buttonSprite);


        sf::Text text;
        text.setFont(GameController::getInstance()->standardFont);

        text.setString(button->getText());

        text.setCharacterSize(button->getFontSize());

        text.setPosition(sf::Vector2f(button->getPosition().x - text.getLocalBounds().width/2,button->getPosition().y -text.getLocalBounds().height/2));


        text.setFillColor(sf::Color::Red);

        //text.setStyle(sf::Text::Bold | sf::Text::Underlined);

        window.draw(text);
    }



}
