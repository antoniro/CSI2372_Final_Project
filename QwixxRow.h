//
//  QwixxRow.h
//  FProject
//

#pragma once
#ifndef QwixxRow_h
#define QwixxRow_h

#include <array>
#include <vector>
#include "Colour.h"
#include "RollOfDice.h"
#include <iomanip>
#include <stdexcept>

template< class T, Colour C>
class QwixxRow {
protected:
    T row;
public:
    QwixxRow<T,C>();
   
   QwixxRow<T,C>& operator+=(const RollOfDice&);
    void rInitialize();
    bool validate(const RollOfDice&);
    bool loopRY(int &);
    bool loopBG(int &);
    void initialize();
    QwixxRow<T,C>& operator+=(const QwixxRow&);
    int& operator[] (const int&);
    
    friend std::ostream& operator<<(std::ostream& os, QwixxRow<T,C>& qRow)
        {
        os<<std::setw(2)<< " | ";
        for ( auto current = qRow.row.begin(); current != qRow.row.end(); ++ current ) {
            if(*current==-1){
                os<<std::setw(2)<<  "XX" <<"| ";
            }
            else{
                os<<std::setw(2)<<  *current <<"| ";
                }
         }
     // if last index is crossed lock row
       if(*(--qRow.row.end())== -1){
          os<<"L";
        }
        else{
          os<<"U";
        }
        std::cout<<"\n";
        return os;
    }
    
protected:
    int index;
    int rIndex;
    
};

template <class T,Colour C>
void QwixxRow<T,C>::initialize(){
    for(int z=2; z<13;z++){
        row.push_back(z);
    }
}

template <class T,Colour C>
void QwixxRow<T,C>::rInitialize(){
    for(int z=12; z>1;z--){
        row.push_back(z);
    }}


template <class T,Colour C>
QwixxRow<T,C>::QwixxRow(): index(2),rIndex(12){
    switch(C){
        case Colour::RED:
            initialize();
            break;
        case Colour::BLUE:
            rInitialize();
            break;
        case Colour::GREEN:
            rInitialize();
            break;
        case Colour::YELLOW:
            initialize();
            break;
        default: break;
    }
}

//This deals with the yellow and red rows. and inserts either -1(XX) or the roll scored in appropriate index
template<class T,Colour C>
bool QwixxRow<T,C>::loopRY(int & forLoop){
    bool type=false;
    try{
        if(forLoop==1) throw std::out_of_range("index is out of range");
    }catch(std::out_of_range outofrange){
        std::cout << "OUT OF RANGE" << outofrange.what();
    }
    for ( auto current = row.begin(); current != row.end(); ++ current ) {
        if( (*current)==forLoop){
            if((++current)!=row.end()){
                if(*current==-1){
                    type= false;}
                    if((*(current)+1 > forLoop)){
                    type= true;
                    break;
                    }else{
                    type= false;
                    break;
                }}
            else{
                --current;
                if(*current==-1){
                    std::cout<<"row locked L \n";
                    type= false;}
                else{
                    type=true;}}
                }
        }
    return type;
}


template<class T,Colour C>
bool QwixxRow<T,C>::loopBG(int & forLoop){
    bool type=false;
    try{
        if(forLoop==1) throw std::out_of_range("index is out of range");
    }catch(std::out_of_range outofrange){
        std::cout << "OUT OF RANGE" << outofrange.what();
        
    }
    for ( auto current = row.begin(); current != row.end(); ++ current ) {
        if( *current == forLoop){
            if((++current)!=row.end()){
                if(*current==-1){
                    type= false;
                        }
                    if((*(current)+1 < forLoop)){
                        type= false;}
                    else{
                        type= true;
                        break; }}
                else{
                        --current;
                        if(*current==-1){
                                std::cout<<"row locked L \n";
                            type= false;}
                        else{
                    type=true;}}
            }
        }
    return type;
}  

template<class T,Colour C>
bool QwixxRow<T,C>::validate(const RollOfDice& index){
    int operate=index;
    switch(C){
        case Colour::RED:
            return(loopRY(operate));
            //break;
        case Colour::YELLOW:
            return(loopRY(operate));
            //  break;
        case Colour::GREEN:
            return(loopBG(operate));
            //  break;
        case Colour::BLUE:
            return(loopBG(operate));
            //  break;
        default:break;
    }
}


template<class T, Colour C>
QwixxRow<T,C>& QwixxRow<T,C>::operator+= (const  RollOfDice& newRoll) {
    auto s= row.begin();
    //switch(T){} 
    int dice= newRoll;
    if(validate(newRoll)){
        for ( auto current = row.begin(); current != row.end(); ++ current ) {
            if(*current==dice){
                s = row.erase(current);
                row.insert(s,-1);  
                }
            else{   }
            }
        }
    else{}
    return *this;
}

#endif /* QwixxRow_h */
