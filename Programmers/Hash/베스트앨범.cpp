#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

typedef struct _MyStruct
{
	int ID;
	int plays;
} MyStruct;

bool cmp(MyStruct fir, MyStruct sec)
{
	if (fir.plays > sec.plays)	return true;
	else if (fir.plays == sec.plays)
	{
		return fir.ID < sec.ID;
	}
	return false;
}


vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;

	map<string, int> sum;
	map<string, vector<MyStruct>> m2;
	MyStruct s;

	int size = genres.size();
	for (int i = 0; i < size; i++)
	{
		s.ID = i;
		s.plays = plays[i];
		m2[genres[i]].push_back(s);
		sum[genres[i]] += plays[i];
	}

	// 누적 플레이 횟수로 정렬
	vector<pair<string, int>> vec;
	copy(sum.begin(),
		sum.end(),
		back_inserter<std::vector<pair<string, int>>>(vec));

	std::sort(vec.begin(), vec.end(),
		[](const pair<string, int> l, const pair<string, int> r) {
			return l.second > r.second;
	});

	// 접근하면서 베스트 곡을 뽑음
	for (auto pair: vec)
	{
		sort(m2[pair.first].begin(), m2[pair.first].end(), cmp);
		answer.push_back(m2[pair.first][0].ID);
		if (m2[pair.first].size() >= 2)	answer.push_back(m2[pair.first][1].ID);
	}

	return answer;
}

//int main()
//{
//	
//	vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
//	vector<int> plays =     { 500, 600, 150, 800, 2500 };
//	//
//	// {classic,pop,classic,pop,classic,classic} , {400,600,150,2500,500,500} 
//
//
//
//	//vector<string> genres = { "c", "a", "b", "a", "b", "a", "c", "b", "b", "d", "c", "b" };
//	//vector<int> plays =     { 100, 200, 300, 400, 500, 600, 700 ,800, 100, 200, 300, 400 };
//	////						   0    1    2    3    4    5    6    7    8    9   10   11
//
//
//
//	vector<int> ret = solution(genres, plays);
//
//	for (int i = 0; i < ret.size(); i++)
//		cout << ret[i] << " ";
//
//	return 0;
//}