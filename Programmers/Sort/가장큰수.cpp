#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string fir, string sec)
{
	return fir + sec > sec + fir;
}


string solution(vector<int> numbers) {
	string answer = "";

	vector<string> v;

	for (int i = 0; i < numbers.size(); i++)
	{
		v.push_back(to_string(numbers[i]));
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++)
	{
		answer += v[i];
	}

	if (answer[0] == '0')
		return "0";

	return answer;
}
/*
int main()
{
	vector<int> v = { 3, 30, 34, 5, 9 };
	vector<string> myV = { "9", "5", "3", "30", "34"};

	sort(myV.begin(), myV.end());

	string ret = solution(v);

	return 0;
}
*/