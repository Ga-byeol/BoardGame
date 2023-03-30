#pragma once
#include "Logic.h"

class LogicOmok : public Logic
{

private:
	int move[8][2] = { {-1,0},{-1,1},{0,1} , {1,1},{1,0},{1,-1},{0,-1},{-1,-1} };

	void addItem(int, int, int);
	void analyze(int, int);
public:
	bool setData(int, int);
};

