#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	multiset<int> q;

	int data = 0;
	for (auto s : operations)
	{
		if (s.at(0) == 'D')				//		delete
		{
			if (q.empty())	continue;
			if (s.at(2) == '1')							//		ÃÖ´ñ°ª »èÁ¦
			{
				q.erase(--q.end());
			}
			else
			{
				q.erase(q.begin());
			}
		}
		else											//		insert			
		{
			data = atoi(s.substr(2, s.length()).c_str());
			q.insert(data);
		}
	}

	if (q.empty())
	{
		answer.push_back(0);
		answer.push_back(0);
	}
	else
	{
		answer.push_back(*(--q.end()));
		answer.push_back(*(q.begin()));
	}


	return answer;
}

int main()
{

	vector<string> tc = { "I 16", "D 1" };
	vector<string> tc2 = { "I 7","I 5", "I -5", "D - 1" };
	vector<string> tc3 = { "I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1" };

	solution(tc3);


	return 0;
}