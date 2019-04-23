#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int pCnt = 0;

	// [93,30,55]	[1,30,5]	[2,1]
	int size = progresses.size();		// 3
	while (pCnt != size)
	{
		for (int i = pCnt; i < size; i++)
		{
			progresses[i] += speeds[i];
		}

		int tmp = 0;
		while (progresses[pCnt] >= 100 && pCnt != size)
		{
			pCnt++;
			tmp++;
		}
		if (tmp)	answer.push_back(tmp);
	}

	return answer;
}

vector<int> solution2(vector<int> progresses, vector<int> speeds)
{
	vector<int> answer;
	queue<int> need_Day;


	// [93,30,55]	[1,30,5]	[2,1]
	for (int i = 0; i < progresses.size(); i++)
	{
		if ((100 - progresses[i]) % speeds[i] == 0)	need_Day.push((100 - progresses[i]) / speeds[i]);
		else
			need_Day.push((100 - progresses[i]) / speeds[i] + 1);
	}

	int tmp = need_Day.front();
	while (!need_Day.empty())
	{
		int tmp = need_Day.front();
		int cnt = 0;
		while(!need_Day.empty() && tmp >= need_Day.front())
		{
			need_Day.pop();
			cnt++;
		}
		answer.push_back(cnt);
	}


	return answer;
}

//int main()
//{
//	vector<int> progresses = { 93,30,55 };
//	vector<int> speeds = { 1,30,5 };
//
//	solution2(progresses, speeds);
//}