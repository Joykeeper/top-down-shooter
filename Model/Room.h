#pragma once
#include "GameObject.h"
#include "Characters/Enemies/PistolEnemy.h"
#include <map>

class Room {
    sf::Vector2f position_;
    sf::Vector2f size_;
    std::map<int, std::vector<Enemy*>> waves_;
    int currentWave_;
    bool active;
    bool finished;

public:
    static sf::Vector2i ROOM_SIZE;
    Room(sf::Vector2f pos={(float )ROOM_SIZE.x, (float )ROOM_SIZE.y}):
    position_(pos), size_(sf::Vector2f(800, 600)), currentWave_(0),
    finished(false), active(false){
        for (auto i = 0; i < 3; i++){
            sf::Vector2f pos1(pos.x+20*i,pos.y+20*i);
            sf::Vector2f pos2(pos.x+20 + 20*i,pos.y+20+20*i);
            sf::Vector2f pos3(pos.x+40 + 20*i,pos.y+40+20*i);
            waves_[i] = std::vector<Enemy*> {
                new PistolEnemy(pos1),
                new PistolEnemy(pos2),
                new PistolEnemy(pos3),
            };
        }
    }

    sf::Vector2f getPos();
    sf::Vector2f getSize();

    int getCurrentWave() const;
    std::vector<Enemy*> getCurrentEnemies();
    std::vector<Enemy*> provideEnemies();
    void nextWave();

    void start();
    bool isActive() const;

    bool isFinished() const;

};

