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
public:
	virtual void inputBeforeRoll(RollOfDice& const) = 0;
	virtual void inputAfterRole(RollOfDice& const) = 0;

private:
    bool active;
};


#endif /* Player_h */
