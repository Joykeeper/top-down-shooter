#pragma once
#include "../GameObject.h"
#include "RoomConnector.h"
#include "../Characters/Enemies/PistolEnemy.h"
#include "StaticObjects/Wall.h"
#include "RoomConnections.h"
#include "../Characters/Enemies/Necromancer.h"
#include "../Characters/Enemies/Sunstriker.h"
#include <map>

class Player;

class Room {
    sf::Vector2f position_;
    sf::Vector2f size_;
    std::map<int, std::vector<std::unique_ptr<Enemy>>> waves_;
    std::vector<std::unique_ptr<Wall>> walls_;
    int currentWave_;
    bool finished;

    std::vector<RoomConnections> roomConnections;

public:
    static sf::Vector2f ROOM_SIZE;
    Room(std::pair<int, int> pos, sf::Vector2f size=ROOM_SIZE): size_(size), currentWave_(0),
    finished(false){
        this->position_ = calculateRoomPosition(pos);

        for (auto i = 0; i < 3; i++){
            sf::Vector2f pos1(position_.x+150*i,position_.y+150*i);
            sf::Vector2f pos2(position_.x+150 + 150*i,position_.y+150+150*i);
            sf::Vector2f pos3(position_.x+250 + 150*i,position_.y+250+20*i);
            sf::Vector2f pos4(position_.x+350 + 150*i,position_.y+350+20*i);
            waves_[i] = std::vector<std::unique_ptr<Enemy>>();
            waves_[i].push_back(std::make_unique<Sunstriker>(pos1));
            waves_[i].push_back(std::make_unique<Necromancer>(pos2));
            waves_[i].push_back(std::make_unique<PistolEnemy>(pos3));
            waves_[i].push_back(std::make_unique<Sunstriker>(pos4));

        }

        updateWalls();
//        bool rightConnection = true;
//
//        float conStartPos = (ROOM_SIZE.y/2-RoomConnector::CONNECTOR_SIZE.y/2) /40;
//
//        for (auto i = 0; i < ROOM_SIZE.x/40; i++){
//            if( (rightConnection) && i > conStartPos && i < conStartPos + RoomConnector::CONNECTOR_SIZE.y/ 40 - 1){
//                walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f (i*40, 0)));
//                walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f (i*40, ROOM_SIZE.y-40)));
//
//                walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f (0, i*40)));
//            } else {
//                walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f(i * 40, 0)));
//                walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f(i * 40, ROOM_SIZE.y - 40)));
//
//                walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f(0, i * 40)));
//                walls_.push_back(std::make_unique<Wall>(position_ + sf::Vector2f(ROOM_SIZE.x - 40, i * 40)));
//            }
//        }

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

    static sf::Vector2f calculateRoomPosition(std::pair<int, int>);

};

