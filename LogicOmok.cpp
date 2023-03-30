#include "LogicOmok.h"
#define EMPTY 0

void LogicOmok::addItem(int _dir, int _sr, int _sc)
{
	int _cv = turn;
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
};

void LogicOmok::analyze(int _r, int _c)
{
	for (int d = 0; d < 4; d++)
	{
		for (int i = d; i < 8; i += 4) addItem(i, _r, _c);
		if (length == 4) return;
		length = 0;
	}
}

bool LogicOmok::setData(int _r, int _c)
{
	if (dat[_r][_c] > 0) return false;
	analyze(_r, _c);

	dat[_r][_c] = turn;
	turn = 3 - turn;
	return (length == 4);
}
