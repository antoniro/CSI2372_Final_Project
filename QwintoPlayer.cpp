//
//  QwintoPlayer.cpp
//  FProject
//


#include <stdio.h>
#include "QwintoPlayer.h"

Colour red=Colour::RED;
Colour blue=Colour::BLUE;
Colour yellow=Colour::YELLOW;

QwintoPlayer::QwintoPlayer(std::string playerName): scoreSheet(playerName), Player() {

}



void QwintoPlayer::inputBeforeRoll(RollOfDice &  finalRoll){
    std::cout<<"\n Enter number of dice to be rolled <= 3 \n";
    std::cin>>nOfDice;
    int loop=nOfDice;
    std::string get;
    
    while(loop>=0){
         std::getline(std::cin,get);
        std::cout<<"Choose Colour of dice to be rolled one at a time \n";
        std::cout<<"  RED   ***   YELLOW  *** BLUE \n";
        
       
        if (get.compare("RED")){
            Dice de(red);
            finalRoll.addDice(de);
        }
        else if(get.compare("YELLOW")){ Dice de(yellow);
            finalRoll.addDice(de);}
        else  if(get.compare("BLUE")){
            Dice de(blue);
            finalRoll.addDice(de);
            }
        else{ std::cout<<"You didn't enter a valid colour. Try again !";}
     loop--;
   }
}


void QwintoPlayer::inputAfterRoll(RollOfDice &  finalRoll) {
     std::cout<<"Enter position of score in sheet 0-9 \n";
    int position=0;
    std::cin>>position;
    std::cout<<"Enter digit number correspontding to the colour of row for scoring \n";
    std::cout<<" (Red) 1     (Yellow) 2   (Blue) 3) \n";
    int input;
    std::cin>>input;
    
    switch(input){
        case 1: scoreSheet.score(finalRoll,red,position);
            std::cout<<"\n scoring....in red..........row.... \n";
            break;
        case 2: scoreSheet.score(finalRoll,yellow,position);
                std::cout<<"\n scoring....in....yellow......row.... \n";
            break;
        case 3: scoreSheet.score(finalRoll,blue,position);
            std::cout<<"\n scoring... in.....blue.....row.... \n";
            break;
        default:
            std::cout<<"\n You didn't enter a digit from 1 to 3 inclusive \n";
            std::cout<<" Enter digit corresponding to row for scoring \n";
            std::cout<<" (Red) 1     (Yellow) 2   (Blue) 3 \n";
            std::cout<<".....restarting.............game................. \n";
            break;
    }
    
    
   /* if (input==1){
        scoreSheet.score(finalRoll,red,position);
    }else if(input==2){  scoreSheet.score(finalRoll,yellow,position);
    }else if(input==3){   scoreSheet.score(finalRoll,blue,position);
    }
    else{
        std::cout<<"please choose colour 1(Red)   2(Yellow)   3(Blue)";
    } */
}
