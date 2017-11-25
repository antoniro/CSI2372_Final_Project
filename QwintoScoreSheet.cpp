//
//  QwintoScoreSheet.cpp
//  FProject
//


#include "QwintoScoreSheet.h"


QwintoScoreSheet::QwintoScoreSheet(std::string nName): ScoreSheet(nName) ,tally(0), detCol(false) , redTally(0),blueTally(0),yellowTally(0),finalTotal(0){
   }

void QwintoScoreSheet::setTotal(){
    finalTotal=calcTotal();
}

int QwintoScoreSheet::calcTotal() {
    int total=0;
    int finalTotal=0;
    
    //go through each row and calculate points
    //red row
    
    if(redTally==red.maxSize()){
        total+=red[red.maxSize()-1];
    }else{ total+=redTally;}
    
    if(yellowTally==yellow.maxSize()){
        total+=yellow[yellow.maxSize()-1];
    }else{ total+=yellowTally;}
    
    if(blueTally==blue.maxSize()){
        total+=blue[blue.maxSize()-1];
    }else{ total+=blueTally; }
    
    // bonus computation is missing
    
    total=total-(getFailCount()*5);
    
    return total;
}

bool QwintoScoreSheet::score(RollOfDice& rd,  Colour & newColor, int z){
    int j = rd;
    rd.roll();
    bool score=validate(newColor,z);
    if(score){
        switch(newColor){
            case Colour::RED:
                red[z]=rd;
                redTally++;
                //std::cout<<"here"<<j<<"\n";
                break;
            case Colour::YELLOW:
                yellow[z]=rd;
                yellowTally++;
                //std::cout<<"not yellow here";
                break;
            case Colour::BLUE:
                blue[z]=rd;
                std::cout<<rd;
                blueTally++;
                //std::cout<<"not blue here";
                break;
            default: break;
        }
        
        return true;
    }else{
    std::cout<<"\n roll cannot be scored \n";
        return false;}
}


std::ostream  & QwintoScoreSheet::print(std::ostream & toStream){
    toStream<< "Player name: "<< playerName << "    Points:"<<"\n";
    toStream<< "                 __________________________________________"<<"\n";
    toStream<<""<<"\n";
    toStream<< "Red"<<"                 "<<red<<"\n";
    toStream<< "             ______________________________________________"<<"\n";
    toStream<<""<<"\n";
    toStream<< "Yellow"<<"           "<<yellow<<"\n";
    toStream<< "             __________________________________"<<"\n";
    toStream<<""<<"\n";
    toStream<< "Blue"<<"          "<<blue<<"\n";
    toStream<< "             _______________________________"<<"\n";
    toStream<<""<<"\n";
    toStream<< "Failed Throws: ";
    printCount(std::cout);
    std::cout<<""<<std::endl;
    toStream<<""<<"\n";

    return toStream;
}

 bool QwintoScoreSheet::validate(Colour & qwinto, int & dice){
    switch(qwinto){
        case Colour::RED:
           detCol= red.validate(dice);
            break;
        case Colour::YELLOW:
          detCol=  yellow.validate(dice);
            break;
        case Colour::BLUE:
          detCol=  blue.validate(dice);
            break;
        default: break;
    }
    
    return detCol; 
}
// to be reconsidered
bool QwintoScoreSheet::operator!() const {
    if(failCount==4){ return true;}
    if(tally>=2) return true;
    return false;
}
std::ostream & QwintoScoreSheet::printCount(std::ostream & toStream) const{
    for(int loop=1;loop<getFailCount()+1;loop++){
        toStream<<loop<<" ";
    }
    return toStream;
}

std::ostream& operator<<(std::ostream& os, const QwintoScoreSheet& qwintoS){
    std::cout<< "Player name: "<<std::endl;
    std::cout<< "                   _________________________________________"<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<< "Red"<<"                "<<qwintoS.red<<std::endl;
    std::cout<< "               _____________________________________________"<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<< "Yellow"<<"         "<<qwintoS.yellow<<std::endl;
    std::cout<< "           _____________________________________________"<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<< "Blue"<<"       "<<qwintoS.blue<<std::endl;
    std::cout<< "           _________________________________________"<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<< "Failed Throws:";
    return os;
}


