#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = n;

	for (auto it = lost.begin(); it < lost.end(); it++)
	{
		auto iter = find(reserve.begin(), reserve.end(), *it);
		if (iter != reserve.end())
		{
			reserve.erase(iter);
			lost.erase(it);
		}
	}


	int re_Idx, lo_Idx = 0;
	for(lo_Idx = 0; lo_Idx < lost.size(); lo_Idx++)
	{	
		for (re_Idx = 0; re_Idx < reserve.size(); re_Idx++)
		{
			if (lost[lo_Idx] + 1 >= reserve[re_Idx] && lost[lo_Idx] - 1 <= reserve[re_Idx])
			{
				lost.erase(lost.begin() + lo_Idx);
				reserve.erase(reserve.begin() + re_Idx);
				re_Idx--;
				lo_Idx--;
				break;
			}
		}
	}

	return answer - lost.size();
}

int main()
{
	vector<int> a = { 12, 13, 16, 17, 19, 20, 21, 22 };
	vector<int> b = { 1,22, 16, 18, 9, 10};

	vector<int> c = { 7,8,11,12 };
	vector<int> d = { 1,6,8,10 };

	vector<int> e = { 1, 3, 4, 5 };
	vector<int> f = { 1, 4 };

	vector<int> g = { 2, 3 };
	vector<int> h = { 1 };

	vector<int> i = {1, 2};
	vector<int> j = {2, 3};

	cout << solution(3, i, j) << endl;
	//solution(5, [2,3], [5,3,1]) 
}