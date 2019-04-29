# 순열(Permutation) 알고리즘
순서가 부여된 임의의 집합을 다른 순서로 뒤섞는 연산이다.
```
A - B - C
A - C - B
B - A - C
B - C - A
C - A - B
C - B - A
```
 이렇게 알파벳을 섞으며, 순열의 모든 경우의 수를 구하는 방법을 알아보자<br><br>
![Permutation](./img/Permutation.gif)

## 과정
그림을 보면서 과정을 설명 하겠다.  

그림을 보면 가장 위의 ABC가 한 단계 진행 되면서 ABC, BAC, CBA 이렇게 세 가지로 나뉘게 되고 0번째의 값이 고정되게 된다.  
```
A[0] <-> A[0]               // 사실상 똑같음
A[0] <-> B[1]                
A[0] <-> C[2]
```

다음으로 각각 0번째 문자인 A, B, C로 고정된 상태에서 1번째 문자를 고정 시킬 것이다.
```
// A ? ?
B[1] <-> B[1]
B[1] <-> C[2]

// B ? ?
A[1] <-> A[1]
A[1] <-> C[2]

// C ? ?
B[1] <-> B[1]
B[1] <-> A[2]
```

이렇게 1번째 문자를 고정 시킬 수 있고, 이 과정을 반복하다보면 모든 경우의 수를 다 구할 수 있게 된다.

이 과정을 코드로 구현해보자.


## 재귀를 이용한 구현
```C++
#include <stdio.h>

int cnt;

void swap(char *a, char *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void arr_info(char *arr)
{
	cnt++;
	for (int i = 0; arr[i] != '\0'; i++)
	{
		printf("%C ", arr[i]);
	}
	printf("\n");
}


/*
*	arr   : 데이터를 담고 있는 배열
*	depth : 현재 교환 중인 깊이(처음에는 0)
*	n     : 배열의 크기(고정 값)
*/
void perm(char *arr, int depth, int n)
{
	if (depth == n)
		arr_info(arr);

	for (int i = depth; i < n; i++)
	{
		swap(&arr[i], &arr[depth]);
		perm(arr, depth + 1, n);
		swap(&arr[i], &arr[depth]);
	}
}


int main()
{
	char data[4] = { 'A', 'B', 'C' }; 
	cnt = 0;
	perm(data, 0, 3);

	printf("Count : %d", cnt);

	return 0;	
}
```
1. 반복문을 돌면서 첫번째 swap()에서 [0] <-> [0] //  [1] <-> [0] // [2] <-> [0]의 교환이 이루어진다.

2. 각각 교환이 이루어진 케이스에 따라 [1] <-> [1] // [1] <-> [2]의 교환이 이루어지면서 1번째 요소가 고정이 된다.

실제로 컴퓨터에서 이러한 순서로 진행되지는 않지만 이렇게 생각하는게 이해하기에 조금 더 편하다.  
어떻게 진행되는지는 실제로 보면서 습득하는게 훨씬 더 빠르다.
<br>

두 번째 swap()함수가 있는 이유는 바뀐 데이터를 다시 원래대로 돌려야 되기 때문이다.  
첫 번째 swap() 함수가 동작한 후, perm() 함수에 들어가며 점점 depth만 깊어지고, 두 번째 swap() 함수는 뒤 늦게 작동하는 것을 볼 수 있다.

depth가 충분히 깊어지고나서(하나의 경우의 수가 결정될 때) 작동을 하며, 뒤 섞인 배열을 다시 원래의 상태로 돌려준다.

Ex) A C B -> A B C 

만약 여기서 두 번째 swap()함수가 없다면 배열이 A C B인 상태로 swap()이 진행되어 이상하게 섞일 것이다.


