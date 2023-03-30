#pragma once
#include <iostream>
using namespace std;

class Render
{
protected:	
	int** dat;
	int nSize;
	bool bwide;
	string line[11] = {
		"式","弛",
		"忙","成","忖",
		"戍","托","扣",
		"戌","扛","戎"
	};		
	string stone[2] = { "∞","≒" };	
	void printUITop();	
	string getLine(string, int, int);
	void printUIRight(int);
public:

	void setData(int**, int, bool);

	virtual void printBoard() = 0;
};

