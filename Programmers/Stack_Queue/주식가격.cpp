#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	int time;
	bool ck;

	for (int i = 0; i < prices.size() - 1; i++)
	{
		time = 1;
		for (int j = i + 1; j < prices.size() - 1; j++)
		{
			if (prices[i] <= prices[j])
				time++;

			else
				break;
		}
		answer.push_back(time);
	}

	answer.push_back(0);

	return answer;
}

int main()
{
	vector<int> a = {1, 2, 3, 2, 3};

	vector<int> ret = solution(a);

	ret.push_back(0);

	return 0;
}