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
		"¦¡","¦¢",
		"¦£","¦¨","¦¤",
		"¦§","¦«","¦©",
		"¦¦","¦ª","¦¥"
	};		
	string stone[2] = { "¡Û","¡Ü" };	
	void printUITop();	
	string getLine(string, int, int);
	void printUIRight(int);
public:

	void setData(int**, int, bool);

	virtual void printBoard() = 0;
};

