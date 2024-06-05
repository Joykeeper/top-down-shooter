#pragma once
#include "../GameObject.h"
#include "RoomConnector.h"
#include "../Characters/Enemies/PistolEnemy.h"
#include "StaticObjects/Wall.h"
#include "RoomConnections.h"
#include <map>

class Player;

class Room {
    sf::Vector2f position_;
    sf::Vector2f size_;
    std::map<int, std::vector<std::unique_ptr<Enemy>>> waves_;
    std::vector<std::unique_ptr<Wall>> walls_;
    int currentWave_;
    bool finished;

    //make it work so such thing will be possible : Room(.., RIGHT | TOP);
    std::vector<RoomConnections> connections;

public:
    static sf::Vector2f ROOM_SIZE;
    Room(sf::Vector2f pos, sf::Vector2f size=ROOM_SIZE):
    position_(pos), size_(size), currentWave_(0),
    finished(false){
        for (auto i = 0; i < 3; i++){
            sf::Vector2f pos1(pos.x+20*i,pos.y+20*i);
            sf::Vector2f pos2(pos.x+20 + 20*i,pos.y+20+20*i);
            sf::Vector2f pos3(pos.x+40 + 20*i,pos.y+40+20*i);
            waves_[i] = std::vector<std::unique_ptr<Enemy>>();
            waves_[i].push_back(std::make_unique<PistolEnemy>(pos1));
            waves_[i].push_back(std::make_unique<PistolEnemy>(pos2));
            waves_[i].push_back(std::make_unique<PistolEnemy>(pos3));

        }

        bool rightConnection = true;

        float conStartPos = (ROOM_SIZE.y/2-RoomConnector::CONNECTOR_SIZE.y/2) /40;

        for (auto i = 0; i < ROOM_SIZE.x/40; i++){
            if( (rightConnection) && i > conStartPos && i < conStartPos + RoomConnector::CONNECTOR_SIZE.y/ 40 - 1){
                walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f (i*40, 0)));
                walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f (i*40, ROOM_SIZE.y-40)));

                walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f (0, i*40)));
            } else {
                walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f(i * 40, 0)));
                walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f(i * 40, ROOM_SIZE.y - 40)));

                walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f(0, i * 40)));
                walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f(ROOM_SIZE.x - 40, i * 40)));
            }
        }

    }

    sf::Vector2f getPos();
    sf::Vector2f getSize();

    bool hasPlayerEntered(Player& player);

    int getCurrentWave() const;
    std::vector<std::unique_ptr<Enemy>>& getCurrentEnemies();
    std::vector<std::unique_ptr<Enemy>> provideEnemies();
    void nextWave();

    std::vector<std::unique_ptr<Wall>>& getWalls();

    bool isFinished() const;

};

