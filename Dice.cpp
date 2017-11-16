//
//  Dice.cpp
//  FProject
//
//  Created by Arthur Mbouche on 2017-11-16.
//  Copyright © 2017 Arthur Mbouche. All rights reserved.
//

#include <stdio.h>
#include "Dice.h"


int Dice::roll(){
    
    face= forRoll.random_value();  // generates random values 1 to 6
    return face;
}

std::ostream& operator<<(std::ostream & os , Dice & newDice){
    
    os << newDice.face << "\t";
    return os;
}
