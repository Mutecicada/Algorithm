#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());

	for (int i = 0; i < completion.size(); i++)
	{
		if (participant[i] != completion[i])
			return participant[i];
	}

	return participant[participant.size() - 1];
}

string solution2(vector<string> participant, vector<string> completion) {
	map<string, int> myMap;
	string answer = "";

	for (int i = 0; i < participant.size(); i++)
	{
		myMap[participant[i]]++;
	}

	for (int i = 0; i < completion.size(); i++)
	{
		myMap[completion[i]]++;
	}

	map<string, int>::iterator it;
	for (it = myMap.begin(); it != myMap.end(); it++)
	{
		int n = it->second;
		if (n % 2)
		{
			answer = it->first;
			break;
		}
	}

	return answer;
}