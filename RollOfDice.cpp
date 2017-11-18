//
//  RollOfDice.cpp
//  FProject
//


#include <stdio.h>
#include "RollOfDice.h"

void RollOfDice::roll(){
    //int add;
    for(Dice d: diceRoll){
        std::cout<<d.roll()<< " ";
    }
}
//to be reconsidered as instructions are not clear
RollOfDice::operator int() const{
    int add=0;
    for(Dice d: diceRoll){
        add+=d.face;
        }
    return add;
}

std::ostream& operator<<(std::ostream& os, const RollOfDice & rDice){
    
    for(Dice d: rDice.diceRoll){
        os<<d.face<< " ";
    }
    return os;
}

RollOfDice::RollOfDice(int numberOfDice){
  
    diceRoll.reserve(numberOfDice); //get input from user and reserve a given size for roll
}

void RollOfDice::removeAllDice(){
    
    while(! diceRoll.empty()){
        diceRoll.pop_back();
    }
}

void RollOfDice::addDice(Dice & newDice){
    if(diceRoll.size()<sizeReserved){
        diceRoll.push_back(newDice);
    }else { /* do nothing */}
}

std::vector<Dice> RollOfDice::pair(Dice & white, Dice & dummy){
    //sizeReserved=2;
    addDice(white);
    addDice(dummy);
    roll();
    
    return diceRoll;
}

