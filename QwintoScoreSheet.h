//
//  QwintoScoreSheet.h
//  FProject
//

#ifndef QwintoScoreSheet_h
#define QwintoScoreSheet_h

#pragma once

#include "QwintoRow.h"
#include "ScoreSheet.h"

class QwintoScoreSheet: public ScoreSheet{  
public:
	bool score(RollOfDice& const, Colour const, int = -1) override;
	void setTotal() override;
	bool operator!() const override;
	friend std::ostream& operator<<(std::ostream&, QwintoScoreSheet& const);
    
protected:
    virtual bool validate() override;
    virtual int calcTotal() override;

private:
	QwintoRow<Colour::RED> red;
	QwintoRow<Colour::YELLOW> yellow;
	QwintoRow<Colour::BLUE> blue;
};

std::ostream& operator<<(std::ostream&, QwintoScoreSheet& const);

#endif /* QwintoScoreSheet_h */
