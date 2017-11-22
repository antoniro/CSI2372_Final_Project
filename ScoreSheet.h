#pragma once

#include <string>
#include "RollOfDice.h"
#include "Colour.h"

class ScoreSheet {
public:
	virtual bool score(RollOfDice& const, Colour const, int = -1);
	virtual void setTotal();
	virtual bool operator!() const;
	friend std::ostream& operator<<(std::ostream&, ScoreSheet& const);

protected:
	virtual bool validate() = 0;
	virtual int calcTotal() = 0;
	
private:
	std::string const playerName;
	int failCount;
	int overallScore;
};

std::ostream& operator<<(std::ostream&, ScoreSheet& const);