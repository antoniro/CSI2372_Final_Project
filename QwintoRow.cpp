//
//  QwintoRow.cpp
//  FProject
//


#include "QwintoRow.h"

//https://www.codeproject.com/Articles/48575/How-to-define-a-template-class-in-a-h-file-and-imp

template<Colour C>
QwintoRow<C>::QwintoRow(): invalidIndex(-1),bonusIndex(100){
    for(int j=0;j<row.max_size();++j){
        row[j]=0;
    }
}


template<Colour C>
int& QwintoRow<C>::operator[] (const int& number){
    return row[number];
}

template<Colour C>
bool QwintoRow<C>::validate(const int& index){
    if(index >= 0 && index < row.max_size()) return true;
    return false;
}

//not sure about this
template<Colour C>
std::ostream& operator<<(std::ostream& os, const QwintoRow<C> & qRow ){
  
    for(int s=0; s< qRow.row.max_size(); s++){
        os<< qRow.row[s] << "| ";
    }
    return os;
}

