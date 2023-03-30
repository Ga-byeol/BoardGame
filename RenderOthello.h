#pragma once
#include<iostream>
#include "Render.h"

class RenderOthello : public Render
{
private:

	void printLine(int, int);
	void printLineWide(int);

public:

	void printBoard();

};

