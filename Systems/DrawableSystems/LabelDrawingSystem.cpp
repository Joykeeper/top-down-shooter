//
// Created by Admin on 15.06.2024.
//

#include "LabelDrawingSystem.h"
#include "../../GameController.h"

void LabelDrawingSystem::draw(sf::RenderWindow &window) const {
    auto& labels = GameController::getInstance()->labelHandler.getItems();

    for (auto& label: labels){
        sf::Text text;
        text.setFont(GameController::getInstance()->standardFont);

        text.setString(label->getText());
        int textPixelLength =  text.findCharacterPos(label->getText().size() - 1).x - text.findCharacterPos(0).x;//((label->getFontSize()+4)/2)*label->getTextLength();
        //text.setPosition(label->getPosition() - sf::Vector2f(textPixelLength/4+3, label->getFontSize()/2));
        text.setCharacterSize(label->getFontSize());

        text.setPosition(sf::Vector2f(label->getPosition().x - text.getLocalBounds().width/2, label->getPosition().y - text.getLocalBounds().height/2));


        text.setFillColor(label->getFontColor());

        //text.setStyle(sf::Text::Bold | sf::Text::Underlined);

        window.draw(text);
    }
}
