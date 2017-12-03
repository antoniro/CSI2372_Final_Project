//
//  QwixxScoreSheet.h
//  FProject
//

#pragma once
#ifndef QwixxScoreSheet_h
#define QwixxScoreSheet_h

#include "ScoreSheet.h"
#include <list>
#include <vector>

//#include "ScoreSheet.cpp"

//QwixxScoresheet Class
class QwixxScoreSheet: public ScoreSheet{
public:
    QwixxRow<std::vector<int>, Colour::RED> red;
    QwixxRow<std::vector<int>, Colour::YELLOW> yellow;
    QwixxRow<std::list<int>, Colour::GREEN> green;
    QwixxRow<std::list<int>, Colour::BLUE> blue;
    
    int lockedRow;
    int redTally;
    int yellowTally;  // keep track of number of dice scored in sheet for later score computation
    int blueTally;
    int greenTally;
    
public:
    QwixxScoreSheet(std::string);
    virtual bool score(RollOfDice&, Colour & , int =-1) override;
    virtual void setTotal() override;
    virtual bool operator!() const override;
    std::ostream & print(std::ostream & toStream);
    friend std::ostream& operator<<(std::ostream&, const QwixxScoreSheet&);
    static void TEST_QWIXXSCORESHEET();
    
protected:
    virtual bool validate(Colour & , RollOfDice &,int & ) override;
    virtual int calcTotal() override;
}; 

std::ostream& operator<<(std::ostream& , const QwixxScoreSheet&);

#endif /* QwixxScoreSheet_h */
