#pragma once
#include <iostream>
#include <vector>

#define ARRSIZE 100

using namespace std;

class Logic
{
private:
	
	int gamemode;

protected:
	enum { OMOK, OTHELLO, BINGO};

	int turn;
	int length = 0;
	int** dat;
	int wid, hei;

	pair<int, int> s[ARRSIZE];



public:			
	void removeData();
	void setGameMode(int);
	int** getData();
	void makeData(int, int);
	virtual bool setData(int,int) = 0;
	virtual void fillandmix()
	{
		;
	}	
	string inputData(string);
};

