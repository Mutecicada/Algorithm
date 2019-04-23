#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
	queue<pair<int, int>> q;

	for (int i = 0; i < priorities.size(); i++)
	{
		q.push(pair<int,int>(priorities[i], i));
	}

	sort(priorities.begin(), priorities.end(), greater<int>());
	
	int pop_cnt = 0;
	while (!q.empty())
	{
		if (q.front().first == priorities[pop_cnt])
		{
			if (location == q.front().second)	return ++pop_cnt;
			q.pop();
			pop_cnt++;
		}
		else
		{
			pair<int, int> tmp = q.front();
			q.pop();
			q.push(tmp);
		}
	}

	return pop_cnt;
}

//int main()
//{
//	vector<int> a = { 1, 1, 9, 1, 1, 1 };
//
//	solution(a, 0);
//}