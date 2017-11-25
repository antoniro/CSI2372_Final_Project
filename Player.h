//
//  Player.h
//  FProject
//

#pragma once
#ifndef Player_h
#define Player_h


#include "RollOfDice.h"
#include <string>


class Player {
    
public: virtual void inputBeforeRoll(RollOfDice&) = 0;
        virtual void inputAfterRoll( RollOfDice& ) = 0;
    Player();
    ~ Player()=default;
    
protected:
    bool active;
    int nOfDice;  
};

#endif /* Player_h */
