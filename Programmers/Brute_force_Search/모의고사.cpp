#include <string>
#include <vector>

using namespace std;

int a[5] =  { 1, 2, 3, 4, 5 };
int b[8] =  { 2, 1, 2, 3, 2, 4, 2, 5 };
int c[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<int> cnt(3);

	for (int i = 0; i < answers.size(); i++)
	{
		if (answers[i] == a[i % 5])		cnt[0]++;
		if (answers[i] == b[i % 8])		cnt[1]++;
		if (answers[i] == c[i % 10])	cnt[2]++;
	}
	
	int max = cnt[0] > cnt[1] ? cnt[0] > cnt[2] ? cnt[0] : cnt[2] : cnt[1] > cnt[2] ? cnt[1] : cnt[2];

	for (int i = 0; i < 3; i++)
	{
		if (max == cnt[i])	answer.push_back(i + 1);
	}

	return answer;
}

int main()
{
	vector<int> a = { 1,2,3,4,5 };

	solution(a);

}