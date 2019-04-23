#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(string arrangement) {
	int answer = 0, nowOn = 0;
	stack<char> st;


	for (auto s : arrangement)
	{
		switch (s)
		{
		case '(':
			answer++;
			nowOn++;
			break;

		case ')':
			if (!st.empty())
			{
				if (st.top() == '(')
				{
					nowOn--;
					answer += nowOn - 1;
				}
				else
				{
					nowOn--;
				}
			}
			break;
		}
		st.push(s);
	}

	return answer;
}

//int main()
//{
//	int ret = solution("()(((()())(())()))(())");
//
//	cout << ret << endl;
//
//	return 0;
//}