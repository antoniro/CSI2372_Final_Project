//
//  QwintoScoreSheet.h
//  FProject
//

#pragma once
#ifndef QwintoScoreSheet_h
#define QwintoScoreSheet_h

#include "QwintoRow.h"

//QwintoScoresheet Class
class QwintoScoreSheet: public ScoreSheet{
    QwintoRow<Colour::RED> red;
    QwintoRow<Colour::BLUE > blue;
    QwintoRow<Colour::WHITE> green;
    
public:
    //using Scoresheet::Scoresheet;
    //QwintoScoreSheet(string score) : Scoresheet(score){}
    void setTotal() override;
    virtual bool operator!() const override;
    std::ostream & print(std::ostream & toStream) ;
    virtual bool score(RollOfDice& , Colour newColor, int =-1) override;
    ~QwintoScoreSheet();
    
    
protected:
    virtual bool validate() override;
    virtual int calcTotal() override;
};
#endif /* QwintoScoreSheet_h */
