#pragma once
#include <iostream>
#include "Render.h"
using namespace std;

class RenderOmok : public Render
{
private:

	void printLine(int, int);

public:

	void printBoard();

};

