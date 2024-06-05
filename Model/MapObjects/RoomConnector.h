#pragma once


#include "../GameObject.h"
#include <memory>
#include "StaticObjects/Wall.h"

class RoomConnector : public GameObject{
    bool vertical;
    std::vector<std::unique_ptr<Wall>> walls_;
public:
    static sf::Vector2f CONNECTOR_SIZE;
    RoomConnector(sf::Vector2f pos, bool vertical): GameObject(pos, CONNECTOR_SIZE), vertical(vertical){
        if (!vertical){
            for (auto i = 0; i < CONNECTOR_SIZE.x/40; i++){
                walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f (i*40, 0)));
                walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f (i*40, CONNECTOR_SIZE.y-40)));
            }
        }
        else {
            for (auto i = 0; i < CONNECTOR_SIZE.x/40; i++){
                walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f (0, i*40)));
                walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f (CONNECTOR_SIZE.x-40, i*40)));
            }
        }


    };

    std::vector<std::unique_ptr<Wall>>& getWalls();

};
