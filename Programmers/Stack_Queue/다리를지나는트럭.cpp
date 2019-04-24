#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int sum = 0, count = 0;
	queue<int> q;
	
	for (int i = 0; i < truck_weights.size(); i++)
	{
		int now = truck_weights[i];
		while (true)
		{
			if (q.empty())
			{
				q.push(now);
				count++;
				sum += now;
				break;
			}
			else if (q.size() == bridge_length)
			{
				sum -= q.front();
				q.pop();
			}
			else
			{
				if (sum + now > weight)
				{
					q.push(0);
					count++;
				}
				else
				{
					q.push(now);
					count++;
					break;
				}
			}
		}
	}

	return count + bridge_length;
}

int main()
{
	vector<int> a = { 97, 81, 7, 40, 86, 64, 87, 57, 45, 30, 50 };

	int ret = solution(25, 100, a);
}
