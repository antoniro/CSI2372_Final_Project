//
//  scoresheet.h
//  Qwinto
//
//  Created by Arthur Mbouche and Oscar Anthony Gbegan.
//  Copyright © 2017 Arthur Mbouche. All rights reserved.
//

#ifndef scoresheet_h
#define scoresheet_h

#include <string>
#include <vector>
#include <iostream>
#include <random>
#include <array>

using std::string;
using std::vector;
using std::ostream;
using std::array;






//Scoresheet Class definition
class Scoresheet {
public: string name;


public:
	Scoresheet(string name);

	virtual bool score(vector<Dice>, Dice::Colour newColor, int position) = 0;

	ostream & print(ostream & toStream);


	~Scoresheet();

};
class QwintScoreSheet : public Scoresheet {};

class QwixxScoreSheet : public Scoresheet {};








//**PLayer**//
class Player {
	bool active;
public: virtual void inputBeforeRoll(RollOfDice & rOFDice);
		virtual void inputAfterRole(RollOfDice & rOFDice);
};
class QwintoPlayer : public Player {
public:
	void inputBeforeRoll(RollOfDice & rOFDice);
	void inputAfterRole(RollOfDice & rOFDice);
};
class QwixxPlayer : public Player {
public:
	void inputBeforeRoll(RollOfDice & rOFDice);
	void inputAfterRole(RollOfDice & rOFDice);
};



#endif /* scoresheet_h */
