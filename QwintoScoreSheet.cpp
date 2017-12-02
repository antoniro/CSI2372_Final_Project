//
//  QwintoScoreSheet.cpp
//  FProject
//


#include "QwintoScoreSheet.h"

int QwintoScoreSheet::getTotal() const{
    return finalTotal;
}

QwintoScoreSheet::QwintoScoreSheet(std::string nName): ScoreSheet(nName) ,tally(0) , redTally(0),blueTally(0),yellowTally(0),finalTotal(0){
   }

void QwintoScoreSheet::setTotal(){
    finalTotal=calcTotal();
}

int QwintoScoreSheet::calcTotal() {
    int total=0;
    int redBonus=1;
    int yellowBonus=7;
    int blueBonus=2;
    
    total = numPointsRow();
    // bonus computation is missing
    total += computeBonus(Colour::RED, redBonus);
    redBonus+=5;
    total += computeBonus(Colour::RED, redBonus);
    total += computeBonus(Colour::YELLOW, yellowBonus);
    total += computeBonus(Colour::BLUE, blueBonus);
    blueBonus+=5;
    total += computeBonus(Colour::BLUE, blueBonus);
    total=total-(getFailCount()*5);
    
    return total;
}

int QwintoScoreSheet::computeBonus(Colour c, int z) {
    int score=0;
    switch(c){
        case Colour::RED:
            if(red[z]>0 && (yellow[z+1]>0) && (blue[z+2]>0)) return score= red[z];
            return 0;
            break;
        case Colour::YELLOW:
            if((yellow[z]>0) && (red[z-1]>0) && (yellow[z+1]>0)) return score= yellow[z];
            return 0;
            break;
        case Colour::BLUE:
            if((blue[z]>0) && (yellow[z-1]>0) && (red[z-2]>0)) return score= blue[z];
            return 0;
            break;
        default:break;
    }
return score;
}


int  QwintoScoreSheet::numPointsRow(){
    int total=0;
    //go through each row and calculate points
    //red row
    if(redTally==red.maxSize()){  //check full row
        total+=red[red.maxSize()-1];
    }else{ total+=redTally;}
    if(yellowTally==yellow.maxSize()){
        total+=yellow[yellow.maxSize()-1];
    }else{ total+=yellowTally;}
    
    if(blueTally==blue.maxSize()){
        total+=blue[blue.maxSize()-1];
    }else{ total+=blueTally; }
return total;
}

bool QwintoScoreSheet::score(RollOfDice& rd,  Colour & newColor, int z){
   // int j = rd;
   // rd.roll();
    bool score=validate(newColor,rd,z);
    if(score){
        switch(newColor){
            case Colour::RED:
                red[z]=rd;
                redTally++;
                break;
            case Colour::YELLOW:
                yellow[z]=rd;
                yellowTally++;
                break;
            case Colour::BLUE:
                blue[z]=rd;
               // std::cout<<rd;
                blueTally++;
                break;
            default: break;
        }
        
        return true;
    }else{
    std::cout<<"\n roll cannot be scored \n";
        return false;}
}


std::ostream  & QwintoScoreSheet::print(std::ostream & toStream){
    std::cout<<"\n";
    toStream<< "Player name: "<< playerName << "    Points:"<<"\n";
    toStream<< "                     ___________________________________________________"<<"\n";
    toStream<<""<<"\n";
    toStream<< "Red"<<"                 "<<red<<"\n";
    toStream<< "                ________________________________________________________"<<"\n";
    toStream<<""<<"\n";
    toStream<< "Yellow"<<"         "<<yellow<<"\n";
    toStream<< "           ________________________________________________________"<<"\n";
    toStream<<""<<"\n";
    toStream<< "Blue"<<"      "<<blue<<"\n";
    toStream<< "           ___________________________________________________"<<"\n";
    toStream<<""<<"\n";
    toStream<< "Failed Throws: ";
    printCount(std::cout);
    std::cout<<""<<std::endl;
    toStream<<""<<"\n";

    return toStream;
}

 bool QwintoScoreSheet::validate(Colour & qwinto,RollOfDice & rd ,int & dice){
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
    std::cout<<"Player name: "<< qwintoS.getPlayerName()<<std::endl;
    std::cout<< "                      ___________________________________________________"<<std::endl;
    std::cout<<""<<std::endl;   
    std::cout<< "Red"<<"                  "<<qwintoS.red<<std::endl;
    std::cout<< "                 ________________________________________________________"<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<< "Yellow"<<"          "<<qwintoS.yellow<<std::endl;
    std::cout<< "            ________________________________________________________"<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<< "Blue"<<"       "<<qwintoS.blue<<std::endl;
    std::cout<< "            ___________________________________________________"<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<< "Failed Throws:";
    return os; 
}


