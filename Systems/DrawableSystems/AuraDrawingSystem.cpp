//
// Created by Admin on 06.06.2024.
//

#include "AuraDrawingSystem.h"
#include "../../GameController.h"

void AuraDrawingSystem::draw(sf::RenderWindow &window) const {
    auto& auras = GameController::getInstance()->auraHandler.getItems();

//    for (auto& aura: auras){
//        sf::CircleShape shape(aura->getRadius());
//        shape.setFillColor(aura->getColor());
//        shape.setPosition(aura->getPosition()-sf::Vector2f(aura->getRadius(), aura->getRadius()));
//        window.draw(shape);
//    }

    for(auto& aura: auras){
        auto auraSprite= aura->getAnimationHandler().getCurrentSprite();
        auraSprite.setPosition(aura->getPosition()-sf::Vector2f(aura->getRadius(), aura->getRadius()));

        window.draw(auraSprite);
        aura->getAnimationHandler().nextFrame();
    }
}
