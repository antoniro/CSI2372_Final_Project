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
    void initialize(int invalid);
   
    friend std::ostream& operator<<(std::ostream& os, const QwintoRow<C>& qRow){
        os<<std::setw(2);
        switch(C){ 
            case Colour::RED:
                for(int z=0; z<qRow.row.size(); z++){
                    if((z==1)||(z==5) ||(z==2)||(z==6)){
                        os<<std::setw(2)<<" % ";
                        if( qRow.row[z]==0){
                          os<<std::setw(2)<<"";
                        }
                        else{
                            os<<std::setw(2)<<qRow.row[z];
                        }
                    }
                    else{
                        os<<std::setw(2)<<" | ";
                        if(qRow.row[z]==-1){
                            os<<"XX";
                        }else if(qRow.row[z]==0){
                            os<<std::setw(2)<<"";
                        }else{
                            os<<std::setw(2)<<qRow.row[z];
                        }
                    }
                }
                os<<" | ";
                break;
            case Colour::YELLOW:
                for(int z=0; z<11 ; z++){
                    if(z==7||(z==8)){
                        os<<std::setw(2)<<" % ";
                        if( qRow.row[z]==0){
                            os<<std::setw(2)<<"";
                        }
                        else{
                            os<<std::setw(2)<<qRow.row[z];
                        }
                    }
                    else{
                        os<<std::setw(2)<<" | ";
                        if(qRow.row[z]==-1){
                            os<<"XX";
                        }else if(qRow.row[z]==0){
                            os<<std::setw(2)<<"";
                        }else{
                            os<<std::setw(2)<<qRow.row[z];
                        }
                    }
                }
                break;
            case Colour::BLUE:
                for(int z=0; z<qRow.row.size()+1; z++){
                    if((z==2)||(z==3) ||(z==9)||(z==10)){
                        os<<std::setw(2)<<" % ";
                        if( qRow.row[z]==0){
                            os<<std::setw(2)<<" ";
                        }
                        else{
                            os<<std::setw(2)<<qRow.row[z];
                        }
                    }
                    else{
                        os<<std::setw(2)<<" | ";
                        if(qRow.row[z]==-1){
                            os<<"XX";
                        }
                        else if(qRow.row[z]==0){
                             os<<std::setw(2)<<"";
                        }else{
                             os<<std::setw(2)<<qRow.row[z];
                        }
                    }
                }
                break;
            default: break;
        }
        return os;
    }
        
private:
    int invalidIndex;
    std::array<int, 10> row;
    int tally;
    
    
};

template<Colour C>
void QwintoRow<C>::initialize(int invalid){
    for(int j=0;j<row.size();++j){
        if(j==invalid){
            row[invalid]=invalidIndex;
        }
        else{
            row[j]=0;
        }
    }
}


template<Colour C>
std::ostream& operator<<(std::ostream& os, const QwintoRow<C>& );

template<Colour C>
bool validate(const int&);

 
template <Colour D>
 QwintoRow<D>::QwintoRow(): invalidIndex(-1){
    
    switch(D){
        case Colour::RED:
            initialize(3);
            break;
        case Colour::YELLOW:
             initialize(5);
                        break;
        case Colour::BLUE:
             initialize(4);
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
