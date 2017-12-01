//
//  RollOfDice.cpp
//  FProject
//

#include <stdio.h>
#include "RollOfDice.h"

void RollOfDice::addDice(Dice & dice)
{
    diceRoll.push_back(dice);
}

void RollOfDice::removeAllDice()
{
    diceRoll.clear();
}

void RollOfDice::roll()
{
    for (Dice &d : diceRoll) {
        d.roll();
    }
}

RollOfDice RollOfDice::pair(Dice & d)
{
    RollOfDice r;
    Dice w(Colour::WHITE);
    w.roll();
    r.addDice(d);
    r.addDice(w);
    return r;
}

std::vector<Dice>::iterator RollOfDice::begin()
{
    return diceRoll.begin();
}

std::vector<Dice>::const_iterator RollOfDice::begin() const
{
    return diceRoll.begin();;
}

std::vector<Dice>::iterator RollOfDice::end()
{
    return diceRoll.end();
}

std::vector<Dice>::const_iterator RollOfDice::end() const
{
    return diceRoll.end();
}

RollOfDice::operator int() const
{
    int result = 0 ;
    for (auto & d : diceRoll) {
        result += d.face;
    }
    
    return result;
}

std::ostream & operator<<(std::ostream & os, RollOfDice const & rd)
{
    // TODO: insert code here
    std::cout<<"\n you rolled ";
    for (auto & d : rd) {
        switch(d.colour)
               {
               case Colour::BLUE:
                   os << "Blue ";
                   break;
               case Colour::RED:
                    os << "RED ";
                       break;
                case Colour::YELLOW:
                       os << "YELLOW ";
                       break;
                case Colour::WHITE:
                       os << "WHITE ";
                       break;
                case Colour::GREEN:
                       os << "GREEN ";
                       break;
               default:break;
               }
        os << ":"<<d.face <<" ";
    }
    
    return os;
}
//convention is to add the 2  white dices at the end of RollOfDice vector
int  RollOfDice::publicNumber(){
    int white=0;
    
    for(int z=0;z<6;++z){
        if((z==4) || (z==5)){
            white+= diceRoll[z].face;
        }
    }
    return white;
}

Dice RollOfDice::getDiceAtI(const int index){
    
    // auto it= std::find(begin(),end(),index);
    Dice find = diceRoll[index];
    //int diceFace= find.face;
    
    return find;
}
