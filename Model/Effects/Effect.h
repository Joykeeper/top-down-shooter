#pragma once

//#include "../Characters/Character.h"

class Character;

class Effect {
protected:
    double effectTime;
    double timeLeft;
    bool finished;
    bool effecting;

public:
    explicit Effect(double  effectTime): effectTime(effectTime),
    timeLeft(effectTime), finished(false), effecting(false){};

    virtual ~Effect() = default;

    bool isFinished() const;
    double getEffectTime() const;
    double getTimeLeft() const;
    bool getEffecting() const;

    void setTimeLeft(double time);

    virtual void effect(Character&) {
        this->effecting = true;
    };
    virtual void uneffect(Character&) {
        this->effecting = false;
    };
};