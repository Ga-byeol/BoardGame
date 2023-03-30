#pragma once
#include "Logic.h"

class LogicOthello : public Logic
{
private:
	int move[8][2] = { {-1,0},{-1,1},{0,1} , {1,1},{1,0},{1,-1},{0,-1},{-1,-1} };
	enum { U, UR, R, DR, D, DL, L, UL };

	void addItem(int, int, int);
	void analyze(int, int);
public:
	bool setData(int, int);
};

