//
//  QwixxScoreSheet.cpp
//  FProject
//

#include "QwixxScoreSheet.h"
QwixxScoreSheet:: QwixxScoreSheet(std::string pName):ScoreSheet(pName),lockedRow(0),greenTally(0),blueTally(0), redTally(0), yellowTally(0){}

void QwixxScoreSheet::setTotal(){
    calcTotal();
}

int QwixxScoreSheet::calcTotal() {
    int total=0;
    int score[] {0,1,3,6,10,15,21,28,36,45,55,66,78};
    //go through each row and calculate points
    //red row
    total += score[redTally];
    total += score[blueTally];
    total += score[greenTally];
    total += score[yellowTally];
    
    total=total-(getFailCount()*5);
    return total;
}

bool QwixxScoreSheet::score(RollOfDice& rd, Colour  & newColor, int z){
    //int score= rd;
    bool score=validate(newColor,rd,z);
    
    if(score){
        switch(newColor){
            case Colour::RED:
                red+=rd;
                redTally++;
                break;
            case Colour::YELLOW:
                yellow+=rd;
                yellowTally++;
                break;
            case Colour::BLUE:
                blue+=rd;
                // std::cout<<rd;
                blueTally++;
                break;
            case Colour::GREEN:
                green+=rd;
                // std::cout<<rd;
                greenTally++;
                break;
            default: break;
        }
        return true;
    }else{
        std::cout<<"\n roll cannot be scored \n";
        return false;}
    return false;
}


std::ostream  & QwixxScoreSheet::print(std::ostream & os){
    os<<"Player name: "<< getPlayerName()<<std::endl;
    os<< "                 _______________________________________________"<<std::endl;
    //  os<<""<<std::endl;
    os<< "Red"<<"             "<<red;
    os<< "                 _______________________________________________"<<std::endl;
    //  os<<""<<std::endl;
    os<< "Yellow"<<"          "<<yellow;
    os<< "                 _______________________________________________"<<std::endl;
    //os<<""<<std::endl;
    os<< "Blue"<<"            "<<blue;
    os<< "                 _______________________________________________"<<std::endl;
    // os<<""<<std::endl;
    os<< "Green"<<"           "<<green;
    os<< "                 _______________________________________________"<<std::endl;
    os<< "Failed Throws:";
    return os;
}

bool QwixxScoreSheet::validate(Colour & qwixx,RollOfDice & j,int & sheet){
    switch(qwixx){
        case Colour::RED:
            detCol= red.validate(j);
            break;
        case Colour::YELLOW:
            detCol=  yellow.validate(j);
            break;
        case Colour::BLUE:
            detCol=  blue.validate(j);
            break;
        case Colour::GREEN:
            detCol=  green.validate(j);
            break;
        default: break;
    }
    return detCol;
}

bool QwixxScoreSheet::operator!() const {
    if(failCount==4) return true;
    
    if(lockedRow>1) return true;
    return false;
}

 std::ostream& operator<<(std::ostream & os, QwixxScoreSheet & qwixx){
     os<<"Player name: "<< qwixx.getPlayerName()<<std::endl;
     os<< "                 _______________________________________________"<<std::endl;
   //  os<<""<<std::endl;
     os<< "Red"<<"             "<<qwixx.red;
     os<< "                 _______________________________________________"<<std::endl;
   //  os<<""<<std::endl;
     os<< "Yellow"<<"          "<<qwixx.yellow;
     os<< "                 _______________________________________________"<<std::endl;
     //os<<""<<std::endl;
     os<< "Blue"<<"            "<<qwixx.blue;
     os<< "                 _______________________________________________"<<std::endl;
    // os<<""<<std::endl;
     os<< "Green"<<"           "<<qwixx.green;
     os<< "                 _______________________________________________"<<std::endl;
     os<< "Failed Throws:";
 return os;
 }


void QwixxScoreSheet::TEST_QWIXXSCORESHEET(){
    QwixxRow<std::vector<int>,Colour::RED> qwixx;
    QwixxRow<std::list<int>,Colour::BLUE> bQwixx;
    std::cout<<qwixx;
    std::cout<<bQwixx;
    Dice blue(Colour::BLUE);
    blue.face=6;
    Dice green(Colour::GREEN);
    green.face=6; 
    RollOfDice rd;
    rd.addDice(blue);
    rd.addDice(green);
    
   // std::cout<<rd;
   // rd.removeAllDice();
     
   // std::cout<<qwixx<<std::endl;
  //  qwixx+=rd;
    //std::cout<<qwixx<<std::endl;
    
    //rd.roll();
    //qwixx+=rd;
   /// qwixx+=rd;
    //std::cout<<qwixx<<std::endl;
   // std::cout<<rd;
    
    QwixxScoreSheet sheet("SPIDER");
    std::cout<<sheet;
}
