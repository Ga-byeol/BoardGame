#pragma once
#include <iostream>
#include "Render.h"
using namespace std;

class RenderBingo : public Render
{
private:

	void printLine(int, int);
	void printLineWide(int,int);

public:

	void printBoard();

};

