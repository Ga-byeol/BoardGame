#include "LogicOthello.h"
#define EMPTY 0

void LogicOthello::addItem(int _dir, int _sr, int _sc)
{
	int _cv = 3 - turn;
	int _sl = length;
	bool _valid = false;

	for (int _r = _sr, _c = _sc; (0 <= _r && _r < hei) && (0 <= _c && _c < wid); _r += move[_dir][0], _c += move[_dir][1])
	{
		if (_r == _sr && _c == _sc) continue;
		if (dat[_r][_c] == EMPTY) break;
		else if (dat[_r][_c] != _cv)
		{
			_valid = true;
			break;
		}
		s[length].first = _r;
		s[length++].second = _c;
	}
	if (_valid == false) length = _sl;
};

void LogicOthello::analyze(int _r, int _c)
{
	length = 0;
	for (int d = U; d <= UL; d++) addItem(d, _r, _c);

	if (length != 0)
	{
		for (int i = 0; i < length; i++) dat[s[i].first][s[i].second] = turn;
	}
}

bool LogicOthello::setData(int _r, int _c)
{
	if (dat[_r][_c] > 0) return false;

	analyze(_r, _c);
	if (length == 0) return false;
	
	dat[_r][_c] = turn;
	turn = 3 - turn;
	return false;
}
