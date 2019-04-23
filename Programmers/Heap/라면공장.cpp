#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k)
{
	int answer = 0;

	priority_queue<int> q;
	
	int day = 0;
	bool ck = true;
	do
	{
		if (ck)
		{
			for (int i = day; i < dates.size(); i++)
			{
				if (dates[i] <= stock)
				{
					q.push(supplies[i]);
				}
				else
				{
					day = i;
					break;
				}
			}
		}
		if (q.size() == supplies.size())	ck = false;
		answer++;
		stock += q.top();
		q.pop();
	} while (stock < k);
	
	return answer;
}

int main()
{
	vector<int> a = { 1, 2, 3, 4 };
	vector<int> b = { 10, 40, 30, 20 };
	solution(4, a, b, 100);

	return 0;
}