//
//  ScoreSheet.h
//  FProject
//
#pragma once
#ifndef ScoreSheet_h
#define ScoreSheet_h


#include <string>
#include "RollOfDice.h"
#include "QwixxRow.h"
#include "QwintoRow.h"


class ScoreSheet {  //Abstract class
public:
   
    ScoreSheet(std::string pName);
    virtual bool score(RollOfDice& , Colour &, int = -1);
    virtual void setTotal();
    virtual bool operator!() const;
    friend std::ostream& operator<<(std::ostream&, const ScoreSheet&);
    int getFailCount() const{return failCount;}
    void incCount(){failCount++;}
    virtual ~ScoreSheet() = default;
    std::string getPlayerName() const{ return playerName;}
    
protected:
    virtual bool validate(Colour &, RollOfDice &,int & j) = 0;
    virtual int calcTotal() = 0;
   
protected:
    std::string playerName;
    int failCount;
    int overallScore;
    bool detCol;
};

std::ostream& operator<<(std::ostream&, const ScoreSheet&);

#endif /* ScoreSheet_h */
