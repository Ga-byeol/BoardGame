#pragma once
#include "Logic.h"
#include <time.h>

class LogicBingo : public Logic
{
private:
	
	int move[8][2] = { {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1} };
	int bingo = 0;

	void addItem(int,int);
	void analyze(int);
	void checknum(int);
	void mixnum(int*);
	void fillnum(int*,int);
public: 
	bool setData(int, int);
	void fillandmix();
};

