#include "Logic.h"
#define EMPTY 0
#define ERROR -1
#define player1 0
#define player2 5
#include <time.h>

int** Logic::getData()
{
	return dat;
}

void Logic::makeData(int _r, int _c)
{
	dat = new int* [_r];
	dat[0] = new int[_r * _c];
	for (int r = 1; r < _r; r++) dat[r] = dat[r - 1] + _c;

	memset(dat[0], 0, sizeof(int) * _r * _c);

	turn = 1;
	hei = _r;
	wid = _c;
}

void Logic::setGameMode(int _newmode)
{
	gamemode = _newmode;
	if (gamemode == OTHELLO)
	{
		dat[3][3] = dat[4][4] = 1;
		dat[4][3] = dat[3][4] = 2;
	}
}

void Logic::removeData()
{
	delete[] dat[0];
	delete[] dat;
}

string Logic::inputData(string _in)
{
	int v = (int)_in[0];
	int _r = (v < 97) ? v - 48 : v - 87;

	v = (int)_in[1];
	int _c = (v < 97) ? v - 48 : v - 87;

	_in[0] = _r;
	_in[1] = _c;

	return _in;
}
