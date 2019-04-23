#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;



int solution(vector<int> citations) {
	sort(citations.begin(), citations.end(), greater<int>());

	//// h번 이상 인용된 논문이 h편 이상이되는 h의 최대값
	// h_Index는 citations의 값 중 하나

	int h_index = citations[0];
	for (int i = 0; i < citations.size(); i++)
	{
		if (citations[i] <= i + 1)	return h_index;
		h_index--;
	}
	return h_index;
}




int solution2(vector<int> citations) {
	sort(citations.begin(), citations.end(), greater<int>());
	for (int i = 0; i < citations.size(); i++)
	{
		if (citations[i] < i + 1)	return i;
	}
}
//
//int main()
//{
//	vector<int> citations;
//
//	srand((unsigned int)time(NULL));
//
//	while (1)
//	{
//
//		srand((unsigned int)time(NULL));
//
//		for (int i = 0; i < 100; i++)
//			citations.push_back(rand() % 100);
//
//		int ret = solution(citations);
//		int ret2 = solution2(citations);
//		if (ret != ret2)
//		{
//			cout << ret << endl << solution2(citations) << endl;
//			system("pause");
//			break;
//		}
//		else
//		{
//			cout << ret << endl << solution2(citations) << endl;
//		}
//		citations.clear();
//	}
//	return 0;
//
//}