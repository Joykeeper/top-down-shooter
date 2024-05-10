//
// Created by Admin on 03.05.2024.
//

#include "ProjectileDrawingSystem.h"
#include "../../GameController.h"

void ProjectileDrawingSystem::draw(sf::RenderWindow &window) const {
    sf::CircleShape shape(20);
    shape.setFillColor(sf::Color::Green);

    auto projectiles = GameController::getInstance()->projectileHandler.getItems();

    for(auto proj: projectiles){
        shape.setPosition(proj->getPos());
        window.draw(shape);
    }
}
