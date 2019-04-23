#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;

	priority_queue<int, vector<int>, greater<int>> q(scoville.begin(), scoville.end());

	do
	{
		if (q.size() < 2)	return -1;
		int a = q.top();
		q.pop();

		int b = q.top();
		q.pop();

		q.push(a + (b * 2));
		answer++;

	} while (q.top() <= K);
	


	return answer;
}