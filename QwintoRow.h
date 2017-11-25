//
//  QwintoRow.h
//  FProject
//

#pragma once
#ifndef QwintoRow_h
#define QwintoRow_h

#include <array>
#include <vector>
#include <iostream>
#include "RollOfDice.h"
#include <iomanip>


template<Colour C>
class QwintoRow {
public:
    QwintoRow<C>();
    bool validate(const int&);
    int& operator[] (const int&);
   int maxSize( )const{return row.max_size();}
  //  int size() const{return row.size();}
    
   
    friend std::ostream& operator<<(std::ostream& os, const QwintoRow<C>& qRow){
        
        switch(C){
            case Colour::RED:
        os<<std::setw(2)<< "| "<<qRow.row[0]<<" % "<<qRow.row[1]<<" % "
        <<qRow.row[2]<<" | "<<"XX"<<"| "<<qRow.row[4]<<" % "<<qRow.row[5]<<" % "<<qRow.row[6]<<" | "
        <<qRow.row[7]<<" | "<<qRow.row[8]<<" | "<<qRow.row[9]<<" | " ;
                break;
            case Colour::YELLOW:
                os<<std::setw(2)<< "| "<<qRow.row[0]<<" | "<<qRow.row[1]<<" | "
                <<qRow.row[2]<<" | "<< qRow.row[3]<<" | "<<qRow.row[4]<<" | "<<"XX"<<"| "<<qRow.row[6]<<" % "
                <<qRow.row[7]<<" % "<<qRow.row[8]<<" | "<<qRow.row[9]<<" | " ;
                break;
            case Colour::BLUE:
                os<<std::setw(2)<< "| "<<qRow.row[0]<<" | "<<qRow.row[1]<<" % "
                <<qRow.row[2]<<" % "<<qRow.row[3]<<" | "<<"XX"<<"| "<<qRow.row[5]<<" | "<<qRow.row[6]<<" | "
                <<qRow.row[7]<<" | "<<qRow.row[8]<<" % "<<qRow.row[9]<<" % " ;
                break;
            default: break;
        }
        return os;
    }
    

        
    
    
private:
    int invalidIndex;
    std::vector<int> bonusIndex;
    std::array<int, 10> row;
    int tally;
    
    
};

template<Colour C>
std::ostream& operator<<(std::ostream& os, const QwintoRow<C>& );

template<Colour C>
bool validate(const int&);


template <Colour D>
 QwintoRow<D>::QwintoRow(): invalidIndex(-1),bonusIndex(100){
    
    switch(D){
        case Colour::RED:
            for(int j=0;j<row.size();++j){
                if(j==3){
                    row[j]=invalidIndex;
                }
                else{
                    row[j]=0;
                }
            }
            break;
        case Colour::YELLOW:
            for(int j=0;j<row.size();++j){
                if(j==5){
                    row[j]=invalidIndex;
                        }
                else{
                    row[j]=0;
                }
            }
            break;
        case Colour::BLUE:
            for(int j=0;j<row.size();++j){
                if(j==4){
                    row[j]=invalidIndex;
                }
                else{
                    row[j]=0;
                }
                
            }
            break;
        default: break;
    }
}


template<Colour C>
int& QwintoRow<C>::operator[] (const int& number){ 
    return row[number];
}
 
template<Colour C>
bool QwintoRow<C>::validate(const int& index){
    if(index < 0 || index > row.max_size()) {
        return false;
         }
    if(row[index]==0) {return true;}
    else{
        return false;
    }
}

#endif /* QwintoRow_h */
