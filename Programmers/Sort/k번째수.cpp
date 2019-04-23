#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	vector<int>::iterator first;
	vector<int>::iterator second;

	for (int i = 0; i < commands.size(); i++)
	{
		first = array.begin() + commands[i][0] - 1;
		second = array.begin() + commands[i][1];
		vector<int>  temp(first, second);
		
		sort(temp.begin(), temp.end());

		answer.push_back(temp[commands[i][2] - 1]);
	}
	// [ 1, 5, 2, 6, 3, 7, 4 ]
	//  5, 2, 6, 3
	return answer;
}
/*
int main()
{
	vector<int> v = { 1, 5, 2, 6, 3, 7, 4 };

	// [[2, 5, 3], [4, 4, 1], [1, 7, 3]]	

	vector<vector<int>> commands = { {2, 5, 3}, {4, 4, 1}, {1, 7, 3} };

	vector<int> ret = solution(v, commands);

	return 0;
}
*/