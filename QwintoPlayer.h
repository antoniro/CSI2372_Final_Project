//
//  QwintoPlayer.h
//  FProject
//
#pragma once
#ifndef QwintoPlayer_h
#define QwintoPlayer_h

#include "RollOfDice.h"
#include "Player.h"
#include "QwintoScoreSheet.h"

class QwintoPlayer : public Player {
public:
    virtual void inputBeforeRoll( RollOfDice &) override;
    void inputAfterRoll( RollOfDice &) override;
    QwintoPlayer(std::string);
    //ScoreSheet& getScoreSheet(){ return scoreSheet;}
public:
    QwintoScoreSheet scoreSheet;
    
   
};

#endif /* QwintoPlayer_h */
