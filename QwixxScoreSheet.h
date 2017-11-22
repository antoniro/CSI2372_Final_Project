//
//  QwixxScoreSheet.h
//  FProject
//


#ifndef QwixxScoreSheet_h
#define QwixxScoreSheet_h

#pragma once

#include <vector>
#include <list>
#include "ScoreSheet.h"
#include "QwixxRow.h"

class QwixxScoreSheet: public ScoreSheet{
public:
	bool score(RollOfDice& const, Colour const, int = -1) override;
	void setTotal() override;
	bool operator!() const override;
	friend std::ostream& operator<<(std::ostream&, QwixxScoreSheet& const);

protected:
	virtual bool validate() override;
	virtual int calcTotal() override;

private:
	QwixxRow<std::vector<int>, Colour::RED> red;
	QwixxRow<std::vector<int>, Colour::YELLOW> yellow;
	QwixxRow<std::list<int>, Colour::GREEN> green;
	QwixxRow<std::list<int>, Colour::BLUE> blue;
};

std::ostream& operator<<(std::ostream&, QwixxScoreSheet& const);

#endif /* QwixxScoreSheet_h */
