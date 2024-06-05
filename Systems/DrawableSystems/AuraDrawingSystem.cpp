//
// Created by Admin on 06.06.2024.
//

#include "AuraDrawingSystem.h"
#include "../../GameController.h"

void AuraDrawingSystem::draw(sf::RenderWindow &window) const {
    auto& auras = GameController::getInstance()->auraHandler.getItems();

    for (auto& aura: auras){
        sf::CircleShape shape(aura->getRadius());
        shape.setFillColor(sf::Color::White);
        shape.setPosition(aura->getPosition()-sf::Vector2f(aura->getRadius(), aura->getRadius()));
        window.draw(shape);
    }
}
