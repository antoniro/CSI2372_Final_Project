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
#include "QwixxScoreSheet.h"

class QwixxPlayer : public Player {
public:
	void inputBeforeRoll(RollOfDice& const) override;
	void inputAfterRole(RollOfDice& const) override;

private:
	QwixxScoreSheet scoreSheet;
};

#endif /* QwixxPlayer_h */
