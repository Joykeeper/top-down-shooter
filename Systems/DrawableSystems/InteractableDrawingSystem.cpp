//
// Created by Admin on 10.05.2024.
//

#include "InteractableDrawingSystem.h"
#include "../../GameController.h"

void InteractableDrawingSystem::draw(sf::RenderWindow &window) const {
    auto interactables = GameController::getInstance()->interactableHandler.getItems();


    auto shape = sf::CircleShape();

    for(auto interactable: interactables){
        shape = sf::CircleShape(interactable->getSize().x/2.f);
        shape.setFillColor(sf::Color::Cyan);

        shape.setPosition(interactable->getPos()-interactable->getSize()/2.f);
        window.draw(shape);
    }
}
