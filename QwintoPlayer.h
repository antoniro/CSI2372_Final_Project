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
#include "QwintoScoreSheet.h"

class QwintoPlayer : public Player {
public:
    void inputBeforeRoll(RollOfDice& const) override;
    void inputAfterRole(RollOfDice& const) override;

private:
	QwintoScoreSheet scoreSheet;
};

#endif /* QwintoPlayer_h */
