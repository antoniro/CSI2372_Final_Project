//
//  ScoreSheet.cpp
//  FProject
//
#include "ScoreSheet.h"
#include <stdio.h>

ScoreSheet::ScoreSheet(std::string newName):playerName(newName),failCount(0),overallScore(0)
{}


std::ostream& operator<<(std::ostream& os, const ScoreSheet& sheet){
    return os;
}

void ScoreSheet::setTotal(){  calcTotal(); }


bool ScoreSheet::score(RollOfDice& , Colour & b, int z){
    
    return validate(b,z);
}


bool ScoreSheet::operator!() const{
    if (failCount==4) return true;
    return false;
}
