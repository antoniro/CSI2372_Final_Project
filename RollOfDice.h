#ifndef RollOfDice_h
#define RollOfDice_h

#pragma once

#include <vector>
#include <iostream>
#include "Dice.h"

class RollOfDice {
public:
    void addDice(Dice&);
    void removeAllDice();
   Dice  removeDice(int );
    void roll();
    RollOfDice pair(Dice&);
    int  publicNumber();

    // Overload begin() member function for use with range-based for loops
    std::vector<Dice>::iterator begin();
    std::vector<Dice>::const_iterator cbegin() const;
    
    // Overload end() menber function for use with range-based for loops
    std::vector<Dice>::iterator end();
    std::vector<Dice>::const_iterator cend() const;
    
    // Overload conversion operator to int
     operator int () const ;
     Dice getDiceAtI( const int );
    
    friend std::ostream& operator<<(std::ostream&,  RollOfDice &) ;
   static void TEST_ROLLOFDICE();
    
private:
    std::vector<Dice> diceRoll;
};

std::ostream& operator<<(std::ostream&, RollOfDice const&);	// Overload insertion operator for printing a RollOfDice to an output stream

#endif /* RollOfDice_h */
