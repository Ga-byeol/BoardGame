#pragma once
#include <iostream>
#include "LogicOmok.h"
#include "LogicOthello.h"
#include "RenderOmok.h"
#include "RenderOthello.h"
#include "LogicBingo.h"
#include "RenderBingo.h"

using namespace std;

int main()
{
	cout << "Select Game" << endl;
	cout << "(1) Omok  (2) Othello  (3) Bingo\n\n";
	cout << "Input Game Mode : ";

	int gamemode = 0;
	cin >> gamemode;
	int row = 0, col = 0;;

	switch (gamemode)
	{
	case 1:
		row = 16;
		col = 16;
		break;
	case 2 :
		row = 8;
		col = 8;
		break;
	case 3:
		row = 10;
		col = 5;
	}

	Render *r = nullptr;
	Logic *l = nullptr;

	switch (gamemode)
	{
	case 1:
		l = new LogicOmok;
		r = new RenderOmok;
		break;
	case 2:
		l = new LogicOthello;
		r = new RenderOthello;
		break;
	case 3:
		l = new LogicBingo;
		r = new RenderBingo;
		break;
	}

	l->makeData(row, col);
	l->setGameMode(gamemode - 1);
	r->setData(l->getData(), row, (col == 8||col == 5));

	if (gamemode == 3) l->fillandmix();

	string input = "";
	bool bGameover = false;
	

	while (1)
	{
		system("cls");

		 r->printBoard();

		if (bGameover)break;

		cout << "Input : ";
		cin >> input;

		input = l->inputData(input);
		int _r = (int)input[0], _c = (int)input[1];

		bGameover = l->setData(_r, _c);
	}
	l->removeData();
	delete l;
	delete r;
}
