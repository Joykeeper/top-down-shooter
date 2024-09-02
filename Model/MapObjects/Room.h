#pragma once
#include "../GameObject.h"
#include "RoomConnector.h"
#include "../Characters/Enemies/PistolEnemy.h"
#include "StaticObjects/Wall.h"
#include "RoomConnections.h"
#include "../Characters/Enemies/Necromancer.h"
#include "../Characters/Enemies/Sunstriker.h"
#include <map>
#include <iostream>

class Player;

class Room {
    sf::Vector2f position_;
    sf::Vector2f size_;
    std::map<int, std::vector<std::unique_ptr<Enemy>>> waves_;
    std::vector<std::unique_ptr<Wall>> walls_;
    int currentWave_;
    bool finished;

    int numberInLevel;

    std::vector<RoomConnections> roomConnections;

    sf::Texture floorTexture_;
    sf::Sprite floorSprite_;

public:
    static sf::Vector2f ROOM_SIZE;
    Room(std::pair<int, int> pos, int number, sf::Vector2f size=ROOM_SIZE): size_(size), numberInLevel(number), currentWave_(-1),
    finished(false) {

        this->position_ = calculateRoomPosition(pos);

        updateWalls();
        if (!this->getFloorTexture().loadFromFile("assets/stone_floor_40.png"))
        {
            std::cout << "Couldn't load image";
        }

        floorSprite_.setTexture(this->getFloorTexture());
        floorSprite_.setTextureRect(sf::IntRect(0, 0, 40, 40));
        floorSprite_.setScale(sf::Vector2f(4, 4));
    }

    sf::Vector2f getPos();
    sf::Vector2f getSize();

    bool hasPlayerEntered(Player& player);

    int getCurrentWave() const;
    std::vector<std::unique_ptr<Enemy>>& getCurrentEnemies();
    std::vector<std::unique_ptr<Enemy>> provideEnemies();
    void nextWave();

    void setRoomConnections(std::vector<RoomConnections>&);

    std::vector<std::unique_ptr<Wall>>& getWalls();

    bool isFinished() const;

    void updateWalls();

    int getNumber() const;

    void generateWaves(int difficultyLevel);

    static sf::Vector2f calculateRoomPosition(std::pair<int, int>);


    sf::Texture& getFloorTexture();
    sf::Sprite& getFloorSprite();
};

