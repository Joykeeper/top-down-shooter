//
// Created by Admin on 02.05.2024.
//

#include "PlayerDrawingSystem.h"
#include "../../GameController.h"

void PlayerDrawingSystem::draw(sf::RenderWindow &window) const {
    auto player = &GameController::getInstance()->player;

//    sf::RectangleShape rectangle(player->getSize());
//    rectangle.setPosition(player->getPos() - player->getSize()/2.f);
//    window.draw(rectangle);

    auto playerSprite = player->getAnimationHandler().getCurrentSprite();
    playerSprite.setPosition(player->getPos() - player->getSize()/2.f);


    if (GameController::getInstance()->getMousePos().x <= player->getPos().x){
        playerSprite.scale(-1.f,1.f);
        playerSprite.move(sf::Vector2f(player->getSize().x, 0));
    };

    window.draw(playerSprite);

    player->getAnimationHandler().nextFrame();
}