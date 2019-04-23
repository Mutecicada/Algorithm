#include <vector>
#include <math.h>

using namespace std;


int prime(int number)
{
	int i, loop;

	loop = sqrt(number);

	if (number == 1)	return 0;

	for (i = 2; i <= loop; i++)
	{
		if (number % i == 0)	return 0;
	}
	return 1;
}

long long solution(int N) {
	long long answer = 2;

	for (int i = 3; i <= N; i +=2 )
	{
		if (prime(i))	answer += i;
	}

	return answer;
}

long long solution(int N) {
	long long answer = 0; 
	vector<bool> sieve(N + 1); 

	for (int i = 2; i <= N; ++i) 
	{ 
		if (sieve[i] == false) 
		{ 
			answer += i; 
		}
		for (int j = i; j <= N; j+=i)
		{ 
			sieve[j] = true; 
		} 
	} 
	return answer; 
}