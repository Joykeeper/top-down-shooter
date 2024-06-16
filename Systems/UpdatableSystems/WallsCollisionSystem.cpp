//
// Created by Admin on 05.06.2024.
//

#include "WallsCollisionSystem.h"
#include "../../GameController.h"
#include "../../Utils.h"


void collisionCheck(Character* character, Wall* wall);

void WallsCollisionSystem::update(sf::Time) const {
    auto rooms = GameController::getInstance()->currentLevel->getRooms();
    auto &roomConnectors = GameController::getInstance()->currentLevel->getConnectors();
    auto characters = GameController::getInstance()->getCharacters();

    for (auto &room: rooms) {
        for (auto &wall: room->getWalls()) {
            for (auto character: characters) {
                collisionCheck(character, wall.get());
            }
        }
    }

    for (auto &connector: roomConnectors) {
        for (auto &wall: connector->getWalls()) {
            for (auto character: characters) {
                collisionCheck(character, wall.get());
            }
        }
    }
}


void collisionCheck(Character* character, Wall* wall){
    if (Utils::objectsCollide(*character, *wall)) {
        auto collisionVec = character->getPos() - wall->getPos();
        auto moveVector = sf::Vector2f();
        if (abs(collisionVec.x) >= abs(collisionVec.y)) {

            if (collisionVec.x > 0) {
                std::cout << "here\n";
                moveVector = sf::Vector2f(
                        sf::Vector2f(wall->getPos().x + wall->getSize().x / 2 + character->getSize().x / 2,
                                     character->getPos().y));
            } else {
                moveVector = sf::Vector2f(
                        sf::Vector2f(wall->getPos().x - wall->getSize().x / 2 - character->getSize().x / 2,
                                     character->getPos().y));
            }

        } else {

            if (collisionVec.y > 0) {
                moveVector = sf::Vector2f(sf::Vector2f(character->getPos().x,
                                                       wall->getPos().y + wall->getSize().y / 2 +
                                                       character->getSize().y / 2));
            } else {
                moveVector = sf::Vector2f(sf::Vector2f(character->getPos().x,
                                                       wall->getPos().y - wall->getSize().y / 2 -
                                                       character->getSize().y / 2));
            }
            std::cout << moveVector.x << " - x" << moveVector.y << " - y, aamovevector\n";
        }

        character->move(moveVector - character->getPos());

    }
}