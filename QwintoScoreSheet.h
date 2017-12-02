//
//  QwintoScoreSheet.h
//  FProject
//

#pragma once
#ifndef QwintoScoreSheet_h
#define QwintoScoreSheet_h

#include "ScoreSheet.h"

//QwintoScoresheet Class
class QwintoScoreSheet: public ScoreSheet{
public:
    QwintoRow<Colour::RED> red;
    QwintoRow<Colour::BLUE> blue;
    QwintoRow<Colour::YELLOW> yellow;
public:
   // using ScoreSheet::ScoreSheet;
    int getTotal() const;
   QwintoScoreSheet(std::string name);
    virtual void setTotal() override;
    virtual bool operator!() const override;
    std::ostream & print(std::ostream &) ;
    
    virtual bool score(RollOfDice& , Colour &, int =-1) override;
    friend std::ostream& operator<<(std::ostream&, const ScoreSheet&);
    
    std::ostream & printCount(std::ostream &) const;
    int  numPointsRow();
    int computeBonus(Colour , int );
    
protected:
    
    virtual int calcTotal() override;
   virtual bool validate(Colour  & , RollOfDice &, int  & x ) override;
    int tally;
    int redTally;
    int yellowTally;  // keep track of number of dice scored in sheet for later score computation
    int blueTally;
    bool detCol;
    int finalTotal;
    

};

std::ostream& operator<<(std::ostream&, const QwintoScoreSheet&);



#endif /* QwintoScoreSheet_h */
