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
  //  RollOfDice rD;
    
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
    //template<typename Z, Colour D>
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
       // std::cout<<"red push";
        row.push_back(z);
    }
    
}

template <class T,Colour C>
void QwixxRow<T,C>::rInitialize(){
    for(int z=12; z>1;z--){
        row.push_back(z);
      //  std::cout<<"blue push";
    }
    
}


template <class T,Colour C>
QwixxRow<T,C>::QwixxRow(): index(2),rIndex(12){
    
    switch(C){
        case Colour::RED:
            initialize();
           // std::cout<<*row.begin()<<std::endl;
           // std::cout<<*row.end()<<std::endl;
            break;
        case Colour::BLUE:
            rInitialize();
          //  std::cout<<*row.begin()<<std::endl;
           // std::cout<<*row.end()<<std::endl;
 
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

template<class T,Colour C>
bool QwixxRow<T,C>::loopRY(int & forLoop){
    // int loop=0;
    bool type=false;
    try{
        if(forLoop==1) throw std::out_of_range("index is out of range");
    }catch(std::out_of_range outofrange){
        std::cout << "OUT OF RANGE" << outofrange.what();
    }
    for ( auto current = row.begin(); current != row.end(); ++ current ) {
     //   std::cout<<*current<<std::endl;
        if( (*current)==forLoop){
            if((++current)!=row.end()){
                if(*current==-1){
                    //throw std::out_of_range("This is an invalid place for entry");
                    std::cout<<"reached here current =-1 true \n";
                    type= false;}
                
                if((*(current)+1 > forLoop)){
                    //  throw std::out_of_range("Roll cannot be scored in this position ");
                    std::cout<<"validated \n";
                    std::cout<<*(current)<<std::endl;
                    type= true;
                    break;
                }else{
                    type= false;
                    std::cout<<"cannot score here \n";
                    std::cout<<"\n";
                    std::cout<<*(--current )<<" ";
                    std::cout<<*(current)<<" ";
                    std::cout<<*(++current);
                    break;
                }}
            else{
                --current;
                if(*current==-1){
                    //throw std::out_of_range("This is an invalid place for entry");
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
    // int loop=12;
    // auto c=row.begin();   
    bool type=false;
    try{
        if(forLoop==1) throw std::out_of_range("index is out of range");
    }catch(std::out_of_range outofrange){
        std::cout << "OUT OF RANGE" << outofrange.what();
        
    }
    for ( auto current = row.begin(); current != row.end(); ++ current ) {
       // std::cout<<*current<<std::endl;
        if( *current == forLoop){
            if((++current)!=row.end()){
              //  --current;
                if(*current==-1){
                    //throw std::out_of_range("This is an invalid place for entry");
                    type= false;}
                
                if((*(current)+1 < forLoop)){
                    // if next value is less than roll
                    // std::cout<<"cannot score here \n";
                    type= false;}else{
                        type= true;
                        break;
                    }
            }
            else{
                --current;
                if(*current==-1){
                    
                    //throw std::out_of_range("This is an invalid place for entry");
                    std::cout<<"row locked L \n";
                    type= false;}
                else{
                    type=true;}}
        }}
    std::cout<<"reached true \n";
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
            else{   
                // std::cout<<"never executes if loop operator +="<<*current<<std::endl;
            }
        }
    }  
    else{
        std::cout<<"never executes validate"<<std::endl;
    }
    return *this;
}

#endif /* QwixxRow_h */
