#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool com(vector<int> a, vector<int> b)
{
	return a[0] < b[0];
}

struct cmp {
	bool operator()(vector<int> a, vector<int> b) {
		return a[1] > b[1];
	}
};


int solution(vector<vector<int>> jobs) {
	int answer = 0;
	
	bool nowOn = false;
//	priority_queue<pair<int,int>, vector<pair<int, int>>> q;
  priority_queue<vector<int>, vector<vector<int>>, cmp> q;

	sort(jobs.begin(), jobs.end(), com);
	
	int time = 0, i = 0;
	while (1)
	{
		{
			while (i < jobs.size() && time >= jobs[i][0])
			{
				q.push(jobs[i++]);
			}

			if (q.empty())
			{
				if (i >= jobs.size())	break;
				time++;
				continue;
			}
			else
			{
				time += q.top()[1];
				answer += time - q.top()[0]; // 작업 끝난 시간 - 자기가 들어온 시간
				q.pop();
			}
		}
	}

	return answer / jobs.size();
}

int main()
{
	vector<vector<int>> a = { {0, 3},{1, 9},{2, 6} };
	vector<vector<int>> b = { {0, 9},{0, 4},{0, 5},{0, 7},{0, 3}};

	int ret = solution(b);

	int bp = ret;

	return 0;
}