#pragma warning(disable:4996)
#include <stdio.h>

int count;


// 재귀호출
/*
T(n) = 2T(n - 1) + 1
	 = 2(2T(n - 2) + 1) + 1
	 = 2(2(2T(n - 3) + 1) + 1) + 1
	 ....

	 = O(2^n)

*/

// 피보나치 수열 과제 (3/ 20 까지)
// 일차원 배열 추가 : 사이즈 n
// 배열에 피보나치 0, 1,2  .. 배열에 기록해 놓기(DP)
// 배열 값을 이용하여 다시 계산하지 않고 사용(메모이제이션 - 한쪽으로만 치우친 트리)
// 보고서 작성 해야함(깨끗하게 작성)

int rFib(int n) {
	count++;
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return rFib(n - 1) + rFib(n - 2);
}

int main() {
	int n;

	scanf("%d", &n);

	printf("%d - %d", rFib(n), count);

	return 0;
}