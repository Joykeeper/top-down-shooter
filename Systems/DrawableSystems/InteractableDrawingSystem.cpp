//
// Created by Admin on 10.05.2024.
//

#include "InteractableDrawingSystem.h"
#include "../../GameController.h"

void InteractableDrawingSystem::draw(sf::RenderWindow &window) const {
    auto& interactables = GameController::getInstance()->interactableHandler.getItems();


    auto shape = sf::CircleShape();

//    for(auto& interactable: interactables){
//        shape = sf::CircleShape(interactable->getSize().x/2.f);
//        shape.setFillColor(interactable->getColor());
//
//        shape.setOutlineColor(sf::Color(85, 81, 82));
//        shape.setOutlineThickness(3);
//
//        shape.setPosition(interactable->getPos()-interactable->getSize()/2.f);
//        window.draw(shape);
//    }

    for(auto& interactable: interactables){
        auto interactableSprite = interactable->getSprite();
        interactableSprite.setPosition(interactable->getPos() - interactable->getSize()/2.f);
        window.draw(interactableSprite);
    }
}
