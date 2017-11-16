//
//  QwintoPlayer.h
//  FProject
//
//  Created by Arthur Mbouche on 2017-11-16.
//  Copyright © 2017 Arthur Mbouche. All rights reserved.
//

#ifndef QwintoPlayer_h
#define QwintoPlayer_h


#pragma once
#include "RollOfDice.h"
#include "Player.h"
class QwintoPlayer : public Player {
public:
    void inputBeforeRoll(RollOfDice &);
    void inputAfterRole(RollOfDice &);
};

#endif /* QwintoPlayer_h */
