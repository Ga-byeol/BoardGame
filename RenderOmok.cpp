#include "RenderOmok.h"

void RenderOmok::printBoard()
{
	printUITop();

	printLine(2, 0);

	for(int line = 1; line < nSize - 1; line++) printLine(5, line);
	
	printLine(8, nSize - 1);
};

void RenderOmok::printLine(int si, int _r)
{
	string s;
	s = line[si];

	cout << getLine(s, _r, 0);

	s = line[si + 1];
	for (int i = 1; i <= nSize - 2; i++) cout << getLine(s, _r, i);

	s = line[si + 2];

	cout << getLine(s, _r, nSize - 1);
	printUIRight(_r);
}
