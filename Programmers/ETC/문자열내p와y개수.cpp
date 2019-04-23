#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
	int p = 0, y = 0;
	for (int i = 0; i < s.size(); i++)
		switch (s.at(i))
		{
		case 'p':
		case 'P':
			p++;
			break;
		case 'y':
		case 'Y':
			y++;
			break;
		}

	return y == p;
}