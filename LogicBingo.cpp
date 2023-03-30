#include "LogicBingo.h"
#define EMPTY 0
#define player1 0
#define player2 5


void LogicBingo::addItem(int _r,int _c)
{
	if (dat[_r][_c] == 0)length++;
};

void LogicBingo::analyze(int player)
{
	bingo = 0;
	for (int r = player; r < player + 5; r++)
	{
		for (int c = 0; c < 5; c++) addItem(r, c);

		if (length == 5) bingo++;
		length = 0;
	}
	for (int c = 0; c < 5; c++)
	{
		for (int r = player; r < player + 5; r++) addItem(r, c);

		if (length == 5) bingo++;
		length = 0;
	}
	for (int r = player,c = 0; r < player + 5; r++,c++) addItem(r, c);

	if (length == 5) bingo++;
	length = 0;

	for (int r = player, c = 4; r < player + 5; r++, c--) addItem(r, c);

	if (length == 5) bingo++;
	length = 0;

	if (bingo >= 3) return;

}

bool LogicBingo::setData(int _r, int _c)
{
	int num = 0;
	num = (_c != -48) ? _r * 10 + _c : _r;

	checknum(num);

	analyze(player1);

	return (bingo >= 3);

	analyze(player2);

	return (bingo >= 3);
}

void LogicBingo::checknum(int num)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = player1; j < player1 + 5; j++) if (dat[j][i] == num) { dat[j][i] = 0; break; }

		for (int j = player2; j < player2 + 5; j++) if (dat[j][i] == num) { dat[j][i] = 0; break; }
	}
}
void LogicBingo::fillandmix()
{
	int shuffle[25] = { 0 };

	for (int i = 0; i < 25; i++)shuffle[i] = i + 1;
	
	mixnum(shuffle);
	fillnum(shuffle,player1);
	mixnum(shuffle);
	fillnum(shuffle, player2);
	
	return;
}
void LogicBingo::mixnum(int *shuffle)
{
	srand(time(NULL));

	int rd = 0;

	for (int i = 0; i < 25; i++)
	{
		rd = rand()%25;
		if (i == rd)
		{
			i--;
			continue;
		}	
		swap(shuffle[i], shuffle[rd]);
	}

	
}
void LogicBingo::fillnum(int *shuffle,int player)
{
	int cnt = 0;
	if (player == player1)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				dat[i][j] = shuffle[cnt++];
			}
		}
	}
	if (player == player2)
	{
		for (int i = 5; i < 10; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				dat[i][j] = shuffle[cnt++];
			}
		}
	}
}