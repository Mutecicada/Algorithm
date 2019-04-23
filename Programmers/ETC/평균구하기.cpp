#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
	double answer = 0;

	for (auto s : arr)
		answer += s;

	return answer / arr.size();
}