#pragma once

#include "Model/Characters/Player.h"
#include <vector>
#include <memory>
#include "Systems/UpdatableSystems/InputHandlingSystem.h"
#include "Systems/DrawableSystems/PlayerDrawingSystem.h"
#include "Systems/DrawableSystems/CameraMovingSystem.h"
#include "Systems/DrawableSystems/FieldDrawingSystem.h"
#include "Model/Magicball.h"
#include "Systems/DrawableSystems/ProjectileDrawingSystem.h"
#include "Systems/UpdatableSystems/ProjectileHandlingSystem.h"
#include "Model/Characters/Enemies/Enemy.h"
#include "Systems/DrawableSystems/EnemyDrawingSystem.h"
#include "Systems/DrawableSystems/WeaponDrawingSystem.h"
#include "Systems/UpdatableSystems/EnemyHandlingSystem.h"
#include "Systems/UpdatableSystems/WeaponHandlingSystem.h"
#include "Model/OldHandler.h"
#include "Model/Handler.h"
#include "Model/Room.h"
#include "Systems/UpdatableSystems/RoomHandlingSystem.h"
#include "Systems/DrawableSystems/RoomDrawingSystem.h"
#include "Model/Interactables/Interactable.h"
#include "Model/Interactables/HealingSalve.h"
#include "Systems/UpdatableSystems/InteractableHandlingSystem.h"
#include "Systems/DrawableSystems/InteractableDrawingSystem.h"
#include "Systems/UpdatableSystems/EffectPuttingSystem.h"
#include "Systems/UpdatableSystems/EffectRemovingSystem.h"
#include "Model/Interactables/ShieldPotion.h"
#include "Model/Level.h"

class GameController {
public:
    static GameController* instance;

    Player player;

    OldHandler<Enemy> enemyHandler;
    Handler<Magicball> projectileHandler;
    OldHandler<Interactable> interactableHandler;

    Room* activeRoom;
    Level* currentLevel;

    std::vector<DrawableSystem*> drawableSystems;
    std::vector<UpdatableSystem*> updatableSystems;
    sf::View* camera;
    sf::RenderWindow* window;

    GameController(): activeRoom(new Room()) {
        player.setWeapon(std::make_unique<Weapon>(player.getPos(), sf::Vector2f(10, 10),0, AllyOrEnemy::ALLY));
        interactableHandler.add(new HealingSalve(sf::Vector2f(-100, -100), 2));
        interactableHandler.add(new ShieldPotion(sf::Vector2f(-25, -100), 5));
        interactableHandler.add(new ShieldPotion(sf::Vector2f(0, -100), 5));
        this->addUpdatableSystem(new EffectPuttingSystem());
        this->addUpdatableSystem(new InputHandlingSystem());
        this->addUpdatableSystem(new RoomHandlingSystem());
        this->addUpdatableSystem(new InteractableHandlingSystem());
        this->addUpdatableSystem(new WeaponHandlingSystem());
        this->addUpdatableSystem(new EnemyHandlingSystem());
        this->addUpdatableSystem(new ProjectileHandlingSystem());
        this->addUpdatableSystem(new EffectRemovingSystem());


        this->addDrawableSystem(new CameraMovingSystem());
        this->addDrawableSystem(new FieldDrawingSystem());
        //this->addDrawableSystem(new RoomDrawingSystem());
        this->addDrawableSystem(new PlayerDrawingSystem());
        this->addDrawableSystem(new EnemyDrawingSystem());
        this->addDrawableSystem(new WeaponDrawingSystem());
        this->addDrawableSystem(new InteractableDrawingSystem());

        this->addDrawableSystem(new ProjectileDrawingSystem());
    };

    static GameController* getInstance(){
        if(!instance){
            instance = new GameController();
        }
        return instance;
    };

    void setCamera(sf::View&);
    void setWindow(sf::RenderWindow&);


    void runDrawableSystems(sf::RenderWindow&);
    void runUpdatableSystems(sf::Time);

    void addDrawableSystem(DrawableSystem*);
    void addUpdatableSystem(UpdatableSystem*);

    std::vector<Character*> getCharacters() const;

    sf::Vector2f getMousePos() const;
};

