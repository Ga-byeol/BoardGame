#include "Render.h"

void Render::setData(int** _dat, int _size, bool _wide)
{
	dat = _dat;
	nSize = _size;
	bwide = _wide;
	if (bwide) nSize++;
}
string Render::getLine(string _line, int _r, int _c)
{
	if (bwide) return _line;


	int data = dat[_r][_c];
	return (data > 0) ? stone[data - 1] : _line;
}
void Render::printUITop()
{
	if (bwide) cout <<"   0   1   2   3   4   5   6   7";
	else cout << "0 1 2 3 4 5 6 7 8 9 a b c d e f";
	cout << endl;
}

void Render::printUIRight(int _r)
{

		char c = (char)((_r < 10) ? _r + 48 : _r + 87);
		cout << c;
	
	cout << endl;
}