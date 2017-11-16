#pragma once

#include <string>
#include "RollOfDice.h"
#include "Colour.h"

class ScoreSheet {
public:
	virtual bool score(RollOfDice& const, Colour, int = -1);
	virtual void setTotal();
	virtual bool operator!() const;
	friend std::ostream& operator<<(std::ostream&, const ScoreSheet&);

protected:
	virtual bool validate() = 0;
	virtual int calcTotal() = 0;
	
private:
	std::string playerName;
	int failCount;
	int overallScore;
};

std::ostream& operator<<(std::ostream&, const ScoreSheet&);