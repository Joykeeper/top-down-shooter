#pragma once


#include "../GameObject.h"
#include <memory>
#include "StaticObjects/Wall.h"

class RoomConnector{

    std::pair<std::pair<int,int>, std::pair<int,int>> connectionBetweenRooms;

    std::vector<std::unique_ptr<Wall>> walls_;

    sf::Vector2f position_;

    bool closed_;


public:
    static sf::Vector2f CONNECTOR_SIZE;
    RoomConnector(std::pair<int, int> room1, std::pair<int, int> room2): connectionBetweenRooms({room1, room2}),
    closed_(false) {
        auto vertical = room1.first - room2.first == 0;

        this->position_ = calculateConnectorPos(room1, room2);

        openConnector();
//        if (!vertical){
//            for (auto i = 0; i < CONNECTOR_SIZE.x/40; i++){
//                walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f (i*40, 0)));
//                walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f (i*40, CONNECTOR_SIZE.y-40)));
//            }
//        }
//        else {
//            for (auto i = 0; i < CONNECTOR_SIZE.x/40; i++){
//                walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f (0, i*40)));
//                walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f (CONNECTOR_SIZE.x-40, i*40)));
//            }
//        }


    };

    std::vector<std::unique_ptr<Wall>>& getWalls();

    static sf::Vector2f calculateConnectorPos(std::pair<int, int> roomLoc1, std::pair<int, int> roomLoc2);

    sf::Vector2f getPos() const;
    sf::Vector2f getSize() const;

    void closeConnector();
    void openConnector();
    bool isClosed();

    std::pair<std::pair<int,int>, std::pair<int,int>> getConnectionLocs();

};
