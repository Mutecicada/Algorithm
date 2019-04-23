#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

// not using map
bool solution(vector<string> phone_book) {

	sort(phone_book.begin(), phone_book.end());

	for (int i = 1; i < phone_book.size(); i++)
	{
		if (phone_book[i - 1] == phone_book[i].substr(0, phone_book[i - 1].size()))
		{
			return false;
		}
	}

	return true;
}


// using map
/*
*		굳이 map을 사용해야 되는 이유를 모르겠다... 정렬이 되서?
*
*/
bool solution2(vector<string> phone_book) {
	map<string, string> myMap;

	for (int i = 0; i < phone_book.size(); i++)
	{
		myMap[phone_book[i]] = phone_book[i].substr(0, 2);
	}

	map<string, string>::iterator it;
	for (it = myMap.begin(); it != myMap.end(); it++)
	{
		string temp;
		
	}

	return true;
}

/*
int main()
{
	vector<string> myVec;

	myVec.push_back("119");
	myVec.push_back("97674223");
	myVec.push_back("1195524421");

	bool ret = solution2(myVec);

	cout << ret << endl;

	return 0;
}
*/