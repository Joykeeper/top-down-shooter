//
// Created by Admin on 03.05.2024.
//

#include "ProjectileDrawingSystem.h"
#include "../../GameController.h"

void ProjectileDrawingSystem::draw(sf::RenderWindow &window) const {
    auto projectiles = GameController::getInstance()->projectileHandler.getItems();

    for(auto proj: projectiles){
        sf::CircleShape shape(proj->getSize().x/2.f);
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(proj->getPos()-proj->getSize()/2.f);
        window.draw(shape);
    }
}
