#pragma once


#include "../GameObject.h"
#include <memory>
#include "StaticObjects/Wall.h"

class RoomConnector{

    std::pair<std::pair<int,int>, std::pair<int,int>> connectionBetweenRooms;

    std::vector<std::unique_ptr<Wall>> walls_;

    sf::Vector2f position_;

    bool closed_;

    sf::Texture floorTexture_;
    sf::Sprite floorSprite_;


public:
    static sf::Vector2f CONNECTOR_SIZE;
    RoomConnector(std::pair<int, int> room1, std::pair<int, int> room2): connectionBetweenRooms({room1, room2}),
    closed_(false) {

        this->position_ = calculateConnectorPos(room1, room2);

        openConnector();

        if (!floorTexture_.loadFromFile("assets/stone_floor_40.png"))
        {
            std::cout << "Couldn't load image";
        }

        floorSprite_.setTexture(this->floorTexture_);
        floorSprite_.setTextureRect(sf::IntRect(0, 0, 40, 40));
        floorSprite_.setScale(sf::Vector2f(6, 6));

    };

    std::vector<std::unique_ptr<Wall>>& getWalls();

    static sf::Vector2f calculateConnectorPos(std::pair<int, int> roomLoc1, std::pair<int, int> roomLoc2);

    sf::Vector2f getPos() const;
    sf::Vector2f getSize() const;

    void closeConnector();
    void openConnector();
    bool isClosed();

    std::pair<std::pair<int,int>, std::pair<int,int>> getConnectionLocs();

    sf::Sprite& getFloorSprite();

};
