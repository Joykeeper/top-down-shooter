#pragma once

#include "Model/Characters/Player.h"
#include <vector>
#include <memory>
#include "Systems/UpdatableSystem.h"
#include "Systems/DrawableSystem.h"
#include "Model/Magicball.h"
#include "Model/Characters/Enemies/Enemy.h"
#include "Model/Handler.h"
#include "Model/MapObjects/Room.h"
#include "Model/Interactables/Interactable.h"
#include "Model/Interactables/HealingSalve.h"
#include "Model/Interactables/ShieldPotion.h"
#include "Model/MapObjects/Level.h"
#include "Model/Auras/Aura.h"
#include "Model/UI/UIButton.h"
#include "Model/Scenes/SceneManager.h"
#include "Model/UI/UILabel.h"


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
    Handler<UILabel> labelHandler;

    std::unique_ptr<Level> currentLevel;

    sf::Font standardFont;

    SceneManager sceneManager;

    std::vector<std::unique_ptr<DrawableSystem>> drawableSystems;
    std::vector<std::unique_ptr<UpdatableSystem>> updatableSystems;

    sf::View* camera;
    sf::RenderWindow* window;

    int unusedSkillPoints;

    int levelsCompleted;

    GameController(): currentLevel(std::make_unique<Level>()), player(Player()), sceneManager(SceneManager()),
    unusedSkillPoints(2), levelsCompleted(0){
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

        player.setPosition(currentLevel->getPlayerStartPoint());
        //player.setPassiveSkill1(std::make_unique<AttackSpeedEffect>(0.2, 5, true));
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

    void resetGame(){
        currentLevel = std::make_unique<Level>();

        player.resetSelf();

        unusedSkillPoints = 0;
        levelsCompleted = 0;
        enemyHandler.clear();
        enemiesToAdd.clear();
        projectileHandler.clear();
        interactableHandler.clear();
        auraHandler.clear();
        aurasToAdd.clear();
        buttonHandler.clear();
        labelHandler.clear();

        currentLevel->generateLevel(7);

        player.setPosition(currentLevel->getPlayerStartPoint());
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

    void addDrawableSystem(std::unique_ptr<DrawableSystem>);
    void addUpdatableSystem(std::unique_ptr<UpdatableSystem>);

    std::vector<Character*> getCharacters();

    sf::Vector2f getMousePos() const;

};