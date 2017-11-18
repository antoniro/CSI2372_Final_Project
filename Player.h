//
//  Player.h
//  FProject
//


#ifndef Player_h
#define Player_h

#pragma once
#include "RollOfDice.h"
#include <string>

class Player {
    bool active;
    std::string playerName;
    
public: virtual void inputBeforeRoll(RollOfDice & );
    virtual void inputAfterRole(RollOfDice & );
};


#endif /* Player_h */
