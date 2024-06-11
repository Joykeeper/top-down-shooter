//
// Created by Admin on 09.06.2024.
//

#include "ButtonDrawingSystem.h"
#include "../../GameController.h"

void ButtonDrawingSystem::draw(sf::RenderWindow &window) const {
    auto& buttons = GameController::getInstance()->buttonHandler.getItems();

    for (auto& button: buttons){
        sf::RectangleShape rectangle(button->getSize());
        if (button->isSelected()){
            rectangle.setFillColor(button->getSelectedBg());
        } else{
            rectangle.setFillColor(button->getIdleBg());
        }
        rectangle.setPosition(button->getPosition() - button->getSize()/2.f);
        window.draw(rectangle);


        sf::Text text;
        text.setFont(GameController::getInstance()->standardFont);

        text.setString(button->getText());
        int textPixelLength =  text.findCharacterPos(button->getTextLength() - 1).x - text.findCharacterPos(0).x;//((button->getFontSize()+4)/2)*button->getTextLength();
        text.setPosition(button->getPosition() - sf::Vector2f(textPixelLength/4+3, button->getFontSize()/2));

        text.setCharacterSize(button->getFontSize());

        text.setFillColor(sf::Color::Red);

        //text.setStyle(sf::Text::Bold | sf::Text::Underlined);

        window.draw(text);
    }
}
