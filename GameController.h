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
#include "Model/Handler.h"
#include "Model/MapObjects/Room.h"
#include "Systems/UpdatableSystems/RoomHandlingSystem.h"
#include "Systems/DrawableSystems/RoomDrawingSystem.h"
#include "Model/Interactables/Interactable.h"
#include "Model/Interactables/HealingSalve.h"
#include "Systems/UpdatableSystems/InteractableHandlingSystem.h"
#include "Systems/DrawableSystems/InteractableDrawingSystem.h"
#include "Systems/UpdatableSystems/EffectPuttingSystem.h"
#include "Systems/UpdatableSystems/EffectRemovingSystem.h"
#include "Model/Interactables/ShieldPotion.h"
#include "Model/MapObjects/Level.h"
#include "Systems/UpdatableSystems/WallsCollisionSystem.h"
#include "Model/Auras/Aura.h"
#include "Systems/UpdatableSystems/AuraHandlingSystem.h"
#include "Systems/DrawableSystems/AuraDrawingSystem.h"
#include "Model/Auras/BurningAura.h"
#include "Systems/UpdatableSystems/SpellHandlingSystem.h"
#include "Model/Characters/Enemies/Sunstriker.h"
#include "Model/Characters/Enemies/Necromancer.h"
#include "Model/UI/UIButton.h"
#include "Systems/UpdatableSystems/ButtonHandlingSystem.h"
#include "Systems/DrawableSystems/ButtonDrawingSystem.h"
#include "Model/UI/ButtonCommands/QuitCommand.h"
#include "Model/Scenes/SceneManager.h"


class GameController {
public:
    static GameController* instance;

    Player player;

    Handler<Enemy> enemyHandler;
    Handler<Enemy> enemiesToAdd;

    Handler<Magicball> projectileHandler;
    Handler<Interactable> interactableHandler;

    Handler<Aura> auraHandler;
    Handler<Aura> aurasToAdd;

    Handler<UIButton> buttonHandler;

    std::unique_ptr<Level> currentLevel;

    sf::Font standardFont;

    //std::unique_ptr<Scene> sceneToSet;
    SceneManager sceneManager;

    std::vector<DrawableSystem*> drawableSystems;
    std::vector<UpdatableSystem*> updatableSystems;
    sf::View* camera;
    sf::RenderWindow* window;



    GameController(): currentLevel(std::make_unique<Level>()) {
//        player.setWeapon(std::make_unique<Weapon>(player.getPos(), sf::Vector2f(10, 10),0.25, AllyOrEnemy::ALLY));
//        interactableHandler.add(std::make_unique<HealingSalve>(sf::Vector2f(-100, -100), 2));
//        interactableHandler.add(std::make_unique<ShieldPotion>(sf::Vector2f(-25, -100), 5));
//        interactableHandler.add(std::make_unique<ShieldPotion>(sf::Vector2f(0, -100), 5));

        //sceneManager.changeScene(std::make_unique<MenuScene>());

        //enemyHandler.add(std::make_unique<Sunstriker>(sf::Vector2f(100, 100), 100));
        //enemyHandler.add(std::make_unique<Sunstriker>(sf::Vector2f(-100, 100), 100));
        //enemyHandler.add(std::make_unique<Sunstriker>(sf::Vector2f(100, -100), 100));

        //enemyHandler.add(std::make_unique<Necromancer>(sf::Vector2f(500, -100)));
        //enemyHandler.add(std::make_unique<Necromancer>(sf::Vector2f(500, -100)));

//        buttonHandler.add(std::make_unique<UIButton>(sf::Vector2f(400, 200), std::string("New Game"),sf::Vector2f(100, 100)));
//        buttonHandler.add(std::make_unique<UIButton>(sf::Vector2f(400, 310), std::string("Load Game"),sf::Vector2f(100, 100)));
//        auto quitButton = std::make_unique<UIButton>(sf::Vector2f(400, 420), std::string("Quit"),sf::Vector2f(100, 100));
//        quitButton->setCommand(std::make_unique<QuitCommand>());
//        buttonHandler.add(std::move(quitButton));

        //std::cout << standardFont.loadFromFile("/Inter.ttf") << " dasd";

//        this->addUpdatableSystem(new ButtonHandlingSystem());
//        this->addDrawableSystem(new ButtonDrawingSystem());
//        this->addUpdatableSystem(new EffectPuttingSystem());
//        this->addUpdatableSystem(new AuraHandlingSystem());
//        this->addUpdatableSystem(new InputHandlingSystem());
//        this->addUpdatableSystem(new WallsCollisionSystem());
//        this->addUpdatableSystem(new RoomHandlingSystem());
//        this->addUpdatableSystem(new InteractableHandlingSystem());
//        this->addUpdatableSystem(new WeaponHandlingSystem());
//        this->addUpdatableSystem(new EnemyHandlingSystem());
//        this->addUpdatableSystem(new ProjectileHandlingSystem());
//        this->addUpdatableSystem(new SpellHandlingSystem());
//        this->addUpdatableSystem(new EffectRemovingSystem());
//
//
//        this->addDrawableSystem(new CameraMovingSystem());
//        this->addDrawableSystem(new FieldDrawingSystem());
//        this->addDrawableSystem(new RoomDrawingSystem());
//        this->addDrawableSystem(new AuraDrawingSystem());
//        this->addDrawableSystem(new PlayerDrawingSystem());
//        this->addDrawableSystem(new EnemyDrawingSystem());
//        this->addDrawableSystem(new WeaponDrawingSystem());
//        this->addDrawableSystem(new InteractableDrawingSystem());
//
//        this->addDrawableSystem(new ProjectileDrawingSystem());
    };

    void start(){
        standardFont.loadFromFile("assets/myfont.ttf");
        currentLevel->generateLevel(7);

        player.setWeapon(std::make_unique<Weapon>(player.getPos(), sf::Vector2f(10, 10),0.25, AllyOrEnemy::ALLY));
        player.setPosition(currentLevel->getPlayerStartPoint());
//        interactableHandler.add(std::make_unique<HealingSalve>(sf::Vector2f(-100, -100), 2));
//        interactableHandler.add(std::make_unique<ShieldPotion>(sf::Vector2f(-25, -100), 5));
//        interactableHandler.add(std::make_unique<ShieldPotion>(sf::Vector2f(0, -100), 5));
//
//        enemyHandler.add(std::make_unique<Sunstriker>(sf::Vector2f(100, 100), 100));
//        enemyHandler.add(std::make_unique<Sunstriker>(sf::Vector2f(-100, 100), 100));
//        enemyHandler.add(std::make_unique<Sunstriker>(sf::Vector2f(100, -100), 100));
//
//        enemyHandler.add(std::make_unique<Necromancer>(sf::Vector2f(500, -100)));
//        enemyHandler.add(std::make_unique<Necromancer>(sf::Vector2f(500, -100)));

        sceneManager.changeScene(std::make_unique<MenuScene>());
    }

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

    std::vector<Character*> getCharacters();

    sf::Vector2f getMousePos() const;
};

