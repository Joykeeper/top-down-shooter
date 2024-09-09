//
// Created by Admin on 11.06.2024.
//

#include "PlayerUIDrawingSystem.h"
#include "../../GameController.h"


void drawHealthAndShield(sf::RenderWindow &, Player& player);
void drawSkills(sf::RenderWindow &, Player& player);
void drawSkillToolBar(sf::RenderWindow &, sf::Vector2f pos);
void drawSkill(sf::RenderWindow &, Spell* skill, sf::Vector2f pos);

void drawEnemyKillPoints(sf::RenderWindow &);

void drawInfoBar(sf::RenderWindow &, sf::Vector2f);
void drawPowerLevel(sf::RenderWindow &, sf::Vector2f);
void drawCompletedLevels(sf::RenderWindow &, sf::Vector2f);

void drawEffects(sf::RenderWindow &, Player& player);
void drawEffectToolBar(sf::RenderWindow &, sf::Vector2f pos);
void drawEffect(sf::RenderWindow &, Effect* skill, sf::Vector2f pos);

void PlayerUIDrawingSystem::draw(sf::RenderWindow &window) const {
    auto mainView = window.getView();
    window.setView(window.getDefaultView());

    auto& player = GameController::getInstance()->player;

    drawHealthAndShield(window, player);

    drawSkills(window, player);

    drawEffects(window, player);

    drawEnemyKillPoints(window);
    drawInfoBar(window, sf::Vector2f (1300, 500));

    auto& playerUi = GameController::getInstance()->playerUi;


    window.setView(mainView);
}


void drawHealthAndShield(sf::RenderWindow& window, Player& player){
    auto hpLabel = std::to_string(player.getHealth()) + std::string ("/") + std::to_string(player.getMaxHealth());
    sf::Text text(hpLabel, GameController::getInstance()->standardFont, 24);
    auto p = sf::Vector2f(70, 40) + sf::Vector2f (100, 20);
    text.setPosition(sf::Vector2f(p.x - text.getLocalBounds().width/2, p.y - text.getLocalBounds().height/2));
    text.setFillColor(sf::Color::Black);

    sf::RectangleShape heartIcon(sf::Vector2f(40, 40));
    heartIcon.setFillColor(sf::Color::Red);
    heartIcon.setPosition(sf::Vector2f(20, 40));
    window.draw(heartIcon);

    sf::RectangleShape healthBar(sf::Vector2f(200, 40));
    healthBar.setPosition(sf::Vector2f(70, 40));
    window.draw(healthBar);

    sf::RectangleShape curHealth(sf::Vector2f(((float )player.getHealth()/(float )player.getMaxHealth())*200, 40));
    curHealth.setFillColor(sf::Color::Red);
    curHealth.setPosition(sf::Vector2f(70, 40));
    window.draw(curHealth);

    window.draw(text);

    auto shieldLabel = std::to_string(player.getShieldPoints());
    text.setString(shieldLabel);
    p = sf::Vector2f(20, 110) + sf::Vector2f (20, 20);
    text.setPosition(sf::Vector2f(p.x - text.getLocalBounds().width/2, p.y - text.getLocalBounds().height/2));

    sf::RectangleShape shieldIcon(sf::Vector2f(40, 40));
    shieldIcon.setFillColor(sf::Color::Blue);
    shieldIcon.setPosition(sf::Vector2f(20, 110));
    window.draw(shieldIcon);

    sf::RectangleShape curShield(sf::Vector2f(((float )player.getShieldPoints()/40)*200, 40));
    curShield.setFillColor(sf::Color::Blue);
    curShield.setPosition(sf::Vector2f(70, 110));
    window.draw(curShield);

    window.draw(text);
};

void drawSkills(sf::RenderWindow &window, Player& player){

    drawSkillToolBar(window, sf::Vector2f(55, 445));

    drawSkill(window, player.getActiveSkill1(), sf::Vector2f(70, 500));
    drawSkill(window, player.getActiveSkill2(), sf::Vector2f(140, 500));

};

void drawSkill(sf::RenderWindow &window, Spell* skill, sf::Vector2f pos){
    auto skillFrameSize = sf::Vector2f(50, 50);

    sf::RectangleShape activeSkill1(skillFrameSize);
    sf::RectangleShape cdActiveSkill1(skillFrameSize);

    if (skill){
        sf::Text text;
        text.setFont(GameController::getInstance()->standardFont);

        text.setString(skill->getName());
        int fontSize = 10;
        //int textPixelLength =  text.findCharacterPos(text.getString().getSize() - 1).x - text.findCharacterPos(0).x;
        text.setPosition(pos + sf::Vector2f(skillFrameSize.x/2, skillFrameSize.y/2) - sf::Vector2f((5*text.getString().getSize())/2, fontSize/2));

        text.setCharacterSize(fontSize);

        text.setFillColor(sf::Color::Black);

        //text.setStyle(sf::Text::Bold | sf::Text::Underlined);

        cdActiveSkill1.setFillColor(sf::Color::Cyan);
        cdActiveSkill1.setPosition(pos);

        cdActiveSkill1.setOutlineThickness(2);
        cdActiveSkill1.setOutlineColor(sf::Color::Black);

        activeSkill1.setFillColor(sf::Color::Red);
        activeSkill1.setSize(sf::Vector2f (skillFrameSize.x, skillFrameSize.y-(skill->getTimeTillNext()/skill->getCoolDown())*skillFrameSize.y));
        activeSkill1.setPosition(pos);

        window.draw(cdActiveSkill1);
        window.draw(activeSkill1);

        window.draw(text);
    } else {
        activeSkill1.setFillColor(sf::Color::White);
        activeSkill1.setPosition(pos);
        window.draw(activeSkill1);
    }

};

void drawSkillToolBar(sf::RenderWindow &window, sf::Vector2f pos){
//    sf::RectangleShape skillBar(sf::Vector2f(150, 80));
//    skillBar.setFillColor(sf::Color::White);
//    skillBar.setPosition(pos);
//    window.draw(skillBar);
    auto& playerUi = GameController::getInstance()->playerUi;
    auto skillToolbar = playerUi.activeSkillsBlock->getSprite();

    window.draw(skillToolbar);

    sf::Text text("Skills", GameController::getInstance()->standardFont, 24);
    auto p = pos + sf::Vector2f(150/2, 15);
    text.setPosition(sf::Vector2f(p.x - text.getLocalBounds().width/2, p.y - text.getLocalBounds().height/2));

    text.setFillColor(sf::Color(0, 0, 160));
    window.draw(text);
}

void drawEffects(sf::RenderWindow &window, Player& player){
    drawEffectToolBar(window, sf::Vector2f(20, 200));

    int i = 0;
    for (auto& effect: player.getEffects()){
        drawEffect(window, effect.get(), sf::Vector2f(30 + 60*(i%3), 210 + 60*(i/3)));
        i++;
    }
};

void drawEffect(sf::RenderWindow &window, Effect* effect, sf::Vector2f pos){
    auto effectFrameSize = sf::Vector2f(50, 50);

    sf::RectangleShape effectBox(effectFrameSize);
    sf::RectangleShape effectLifeTime(effectFrameSize);

    sf::Text text;
    text.setFont(GameController::getInstance()->standardFont);

    text.setString(effect->getName());
    int fontSize = 10;
    //int textPixelLength =  text.findCharacterPos(text.getString().getSize() - 1).x - text.findCharacterPos(0).x;
    text.setPosition(pos + sf::Vector2f(effectFrameSize.x/2, effectFrameSize.y/2) - sf::Vector2f((5*text.getString().getSize())/2, fontSize/2));

    text.setCharacterSize(fontSize);

    text.setFillColor(sf::Color::Black);

    //text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    effectLifeTime.setFillColor(sf::Color::Cyan);
    effectLifeTime.setPosition(pos);

    effectLifeTime.setOutlineThickness(2);
    effectLifeTime.setOutlineColor(sf::Color::Black);

    effectBox.setFillColor(sf::Color::Red);
    effectBox.setSize(sf::Vector2f (effectFrameSize.x, effectFrameSize.y-(effect->getTimeLeft()/effect->getEffectTime())*effectFrameSize.y));
    effectBox.setPosition(pos);

    window.draw(effectLifeTime);
    window.draw(effectBox);

    window.draw(text);
}

void drawEffectToolBar(sf::RenderWindow &window, sf::Vector2f pos){
//    sf::RectangleShape effectBar(sf::Vector2f(240, 130));
//    effectBar.setFillColor(sf::Color::White);
//    effectBar.setPosition(pos);
//    window.draw(effectBar);



    auto& playerUi = GameController::getInstance()->playerUi;
    auto effectToolbar = playerUi.passiveSkillsBlock->getSprite();
    window.draw(effectToolbar);

    sf::Text text("Effects", GameController::getInstance()->standardFont, 24);
    auto p = pos + sf::Vector2f(250/2, 15);
    text.setPosition(sf::Vector2f(p.x - text.getLocalBounds().width/2, p.y - text.getLocalBounds().height/2));

    text.setFillColor(sf::Color(0, 0, 160));
    window.draw(text);
};


void drawEnemyKillPoints(sf::RenderWindow &window){
    sf::Text text;
    text.setFont(GameController::getInstance()->standardFont);

    text.setString(std::to_string(GameController::getInstance()->player.getEnemyKillCount()));
    int fontSize = 72;
    //int textPixelLength =  text.findCharacterPos(text.getString().getSize() - 1).x - text.findCharacterPos(0).x;
    text.setPosition(1400, 50);

    text.setCharacterSize(fontSize);

    text.setStyle(sf::Text::Bold);


    text.setFillColor(sf::Color::White);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(10);

    window.draw(text);
}

void drawPowerLevel(sf::RenderWindow &window,  sf::Vector2f pos){
    sf::Text text;
    text.setFont(GameController::getInstance()->standardFont);

    auto skillPoints = GameController::getInstance()->unusedSkillPoints;
    if (skillPoints != 0){
        text.setString(std::string("Power Level: ") + std::to_string(GameController::getInstance()->player.getPowerLevel()) + std::string(" (+" + std::to_string(skillPoints) + std::string(" SP)")));
    } else{
        text.setString(std::string("Power Level: ") + std::to_string(GameController::getInstance()->player.getPowerLevel()));
    }

    int fontSize = 16;

    text.setPosition(pos);

    text.setCharacterSize(fontSize);

    text.setFillColor(sf::Color(235, 103, 34));

    window.draw(text);
}

void drawCompletedLevels(sf::RenderWindow &window, sf::Vector2f pos){
    sf::Text text;
    text.setFont(GameController::getInstance()->standardFont);

    text.setString(std::string("Current Dungeon: ") + std::to_string(GameController::getInstance()->levelsCompleted+1));
    int fontSize = 16;
    //int textPixelLength =  text.findCharacterPos(text.getString().getSize() - 1).x - text.findCharacterPos(0).x;
    text.setPosition(pos);

    text.setCharacterSize(fontSize);

    text.setFillColor(sf::Color(235, 103, 34));

    window.draw(text);
}

void drawInfoBar(sf::RenderWindow &window, sf::Vector2f pos){

    sf::RectangleShape infoBar(sf::Vector2f(250, 200));
    infoBar.setFillColor(sf::Color::White);
    infoBar.setOutlineColor(sf::Color::Black);
    infoBar.setOutlineThickness(5);
    infoBar.setPosition(pos);
    window.draw(infoBar);

    auto& playerUi = GameController::getInstance()->playerUi;
    auto infoBlockSprite = playerUi.infoBlock->getSprite();

    window.draw(infoBlockSprite);


    sf::Text text("Progress", GameController::getInstance()->standardFont, 24);
    auto p = pos + sf::Vector2f(250/2, 15);
    text.setPosition(sf::Vector2f(p.x - text.getLocalBounds().width/2, p.y - text.getLocalBounds().height/2));

    text.setFillColor(sf::Color(0, 0, 160));
    window.draw(text);

    drawCompletedLevels(window, pos + sf::Vector2f(10, 60));
    drawPowerLevel(window, pos+ sf::Vector2f(10, 100));
};
