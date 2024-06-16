#pragma once

//#include "../Characters/Character.h"


#include <string>

class Character;

class Effect {
protected:
    double effectTime;
    double timeLeft;
    bool finished;
    bool effecting;
    std::string name;

    bool passive_;

public:
    explicit Effect(double  effectTime, std::string name = "", bool passive = false): effectTime(effectTime),
    timeLeft(effectTime), finished(false), effecting(false), name(name), passive_(passive){};

    Effect(const Effect& effect): effectTime(effect.getEffectTime()), timeLeft(effect.getEffectTime()),
    finished(false), effecting(false), name(effect.getName()){};

    virtual ~Effect() = default;

    bool isFinished() const;
    double getEffectTime() const;
    double getTimeLeft() const;
    bool getEffecting() const;

    std::string getName() const;

    void setTimeLeft(double time);

    virtual void effect(Character&, float deltaTime=0) {
        this->effecting = true;
    };

    virtual void uneffect(Character&) {
        this->effecting = false;
    };

    bool isPassive();
    void setPassive(bool);
};