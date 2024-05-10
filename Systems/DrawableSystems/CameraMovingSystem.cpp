//
// Created by Admin on 02.05.2024.
//


#include "CameraMovingSystem.h"
#include "../../GameController.h"


void CameraMovingSystem::draw(sf::RenderWindow& window) const{
    auto& player = GameController::getInstance()->player;

    GameController::getInstance()->camera->setCenter(player.getPos());
    window.setView(*GameController::getInstance()->camera);
}
