//
//  QwixxScoreSheet.h
//  FProject
//


#ifndef QwixxScoreSheet_h
#define QwixxScoreSheet_h

#include "ScoreSheet.h"
#include "QwixxRow.h"

//QwixxScoresheet Class
class QwixxScoreSheet: public ScoreSheet{
    QwixxRow<Dice,Colour::RED> red;
    QwixxRow<Dice,Colour::BLUE> blue;
    QwixxRow<Dice,Colour::GREEN> green;
    QwixxRow<Dice,Colour::WHITE> WHITE;

    
public:
    virtual bool score(RollOfDice&, Colour newColor, int =-1);
    virtual void setTotal();
    virtual bool operator!() const;
    virtual std::ostream & print(std::ostream & toStream);
    ~QwixxScoreSheet();
    
protected:
    virtual bool validate();
    virtual int calcTotal();
};

#endif /* QwixxScoreSheet_h */
