#include "RenderBingo.h"
#define player1 0
#define player2 5

void RenderBingo::printBoard()
{
	printLine(2, 0);
	printLine(2, 0);
	cout << endl;

	for (int line = 1; line < 5; line++) {
		printLineWide(line - 1, player1);
		printLineWide(line + 4, player2);
		cout << endl;
		printLine(5, line);
		printLine(5, line);
		cout << endl;
	}
	
	printLineWide(player1 + 4, player1);
	printLineWide(player2 + 4, player2);
	cout << endl;
	printLine(8, nSize - 1);
	printLine(8, nSize - 1);
	cout << endl;
};

void RenderBingo::printLine(int si, int _r)
{
	string s;
	s = line[si];
	cout << getLine(s, 0, 0);

	s = line[0] + line[si + 1];
	for (int i = 1; i <= 4; i++) cout << getLine(s, 0, 0);

	s = line[0] + line[si + 2];
	cout << getLine(s, 0, 0);


}

void RenderBingo::printLineWide(int _r,int player)
{
	string s = line[1];
	cout << s;

	int data;
	for (int _c = 0; _c < 5; _c++)
	{
		data = dat[_r][_c];
		cout << data;
		if (data < 10) cout << " ";
		cout << s;
	}

}
