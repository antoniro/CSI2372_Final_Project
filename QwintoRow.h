//
//  QwintoRow.h
//  FProject
//


#ifndef QwintoRow_h
#define QwintoRow_h

#pragma once

#include <array>
#include <vector>
#include <iostream>
#include "Colour.h"
#include "RollOfDice.h"


template<Colour C>
class QwintoRow {
public:
    QwintoRow();
    bool validate(const int&);
    int& operator[] (const int&);
    
    template<Colour D>
    friend std::ostream& operator<<(std::ostream& , const QwintoRow<D>& );
        
    
    
private:
    int invalidIndex;
    std::vector<int> bonusIndex;
    std::array<int, 10> row;
};

template<Colour C>
std::ostream& operator<<(std::ostream& os, const QwintoRow<C>& );
  // os<<"c";
   // return os;
//}

template<Colour C>
bool validate(const int&);

#endif /* QwintoRow_h */
