#include "RenderOthello.h"

void RenderOthello::printBoard()
{
	printUITop();

	printLine(2, 0);

	for (int line = 1; line < nSize - 1; line++) {
		printLineWide(line - 1);
		printLine(5, line);
	}
	printLineWide(nSize - 2);
	printLine(8, nSize - 1);
};

void RenderOthello::printLine(int si, int _r)
{
	string s;
	s = line[si];
	cout << getLine(s, _r, 0);

	s = line[0] + line[si + 1];
	for (int i = 1; i <= nSize - 2; i++) cout << getLine(s, _r, i);

	s = line[0] + line[si + 2];
	cout << getLine(s, _r, nSize - 1)<< endl;
	
}

void RenderOthello::printLineWide(int _r)
{
	string s = line[1];
	cout << s;

	int data;
	for (int _c = 0; _c < nSize - 1; _c++)
	{
		data = dat[_r][_c];
		cout << ((data > 0) ? stone[data - 1] : "  ") << s;
	}
	printUIRight(_r);
}