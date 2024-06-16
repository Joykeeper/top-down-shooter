//
// Created by Admin on 02.05.2024.
//

#include <iostream>
#include "GameController.h"

void GameController::runUpdatableSystems(sf::Time deltaTime) {
    for(auto& system: this->updatableSystems) system->update(deltaTime);

    sceneManager.setNewScene();
}

void GameController::runDrawableSystems(sf::RenderWindow& window) {
    for(auto& system: this->drawableSystems) system->draw(window);
}

GameController* GameController::instance = nullptr;

void GameController::addDrawableSystem(std::unique_ptr<DrawableSystem> system) {
    this->drawableSystems.push_back(std::move(system));
}
void GameController::addUpdatableSystem(std::unique_ptr<UpdatableSystem> system) {
    this->updatableSystems.push_back(std::move(system));
}


void GameController::setCamera(sf::View& cam) {

    this->camera = &cam;
}

void GameController::setWindow(sf::RenderWindow &window) {
    this->window = &window;
}

sf::Vector2f GameController::getMousePos() const {
    // get the current mouse position in the window
    sf::Vector2i pixelPos = sf::Mouse::getPosition(*window);

    sf::Vector2f worldPos = window->mapPixelToCoords(pixelPos);
    return worldPos;
}

std::vector<Character *> GameController::getCharacters() {
    auto characters = std::vector<Character *>();

    characters.push_back((Character *)&this->player);

    auto& enemies = enemyHandler.getItems();

    for (auto& enemy: enemies){
        characters.push_back(enemy.get());

    }

    return characters;
}
