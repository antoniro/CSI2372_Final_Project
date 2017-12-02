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

std::vector<Dice>::const_iterator RollOfDice::cbegin() const
{
    return diceRoll.begin();;
}

std::vector<Dice>::iterator RollOfDice::end()
{
    return diceRoll.end();
}

std::vector<Dice>::const_iterator RollOfDice::cend() const
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

std::ostream & operator<<(std::ostream & os, RollOfDice & rd)
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
    
    
    Dice const find = diceRoll[index];
   // auto it= std::find(cbegin(),cend(),find);
    //int diceFace= find.face;
    
    return find;
}

Dice  RollOfDice::removeDice(int diceIndex){
    Dice const  find = diceRoll[diceIndex];
    diceRoll.erase(cbegin()+(diceIndex));
    return find;
}

 void RollOfDice::TEST_QWINTOROW(){
    std::cout<<"Testing RollOfDice.cpp \n";
    Dice blue(Colour::BLUE);
    Dice green(Colour::GREEN);
    Dice red(Colour::RED);
    RollOfDice rd; 
    rd.addDice(blue);
    rd.addDice(green);
    rd.addDice(red);
    std::cout<<"Added 3 dices, now rolling \n";
    rd.roll();
    std::cout<<rd;
    std::cout<<"\n Removing  middle dice ";
    rd.removeDice(1);
    std::cout<<rd;
    //rd.roll();
}
