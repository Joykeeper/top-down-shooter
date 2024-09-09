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
#include "Model/UI/UIComponent.h"
#include "Model/UI/PlayerUI.h"


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

    PlayerUI playerUi;

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
    unusedSkillPoints(1), levelsCompleted(0){};

    void start(){
        standardFont.loadFromFile("assets/myfont.ttf");
        currentLevel->generateLevel(7);

        player.setPosition(currentLevel->getPlayerStartPoint());

        sceneManager.changeScene(std::make_unique<MenuScene>());
    }

    void resetGame(){
        currentLevel = std::make_unique<Level>();

        player.resetSelf();

        unusedSkillPoints = 1;
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