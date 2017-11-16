//
//  QwixxPlayer.h
//  FProject
//
//  Created by Arthur Mbouche on 2017-11-16.
//  Copyright © 2017 Arthur Mbouche. All rights reserved.
//


#ifndef QwixxPlayer_h
#define QwixxPlayer_h


#pragma once
#include "RollOfDice.h"
#include "Player.h"

class QwixxPlayer : public Player {
public:
    void inputBeforeRoll( RollOfDice &);
    void inputAfterRole( RollOfDice &);
};

#endif /* QwixxPlayer_h */
