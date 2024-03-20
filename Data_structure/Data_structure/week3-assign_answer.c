#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>

int count = 0;
int memo[100] = { 0, };
// memoization answer

int mrFib(int n) {
	count++;
	if (memo[n] != 0)
		return memo[n];

	if (n == 1 || n == 2)
		return 1;
	else {
		memo[n] = mrFib(n - 1) + mrFib(n - 2);
		return memo[n];
	}
}

// 자체 순환(함수 호출 1번)
int iFib(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;

	int pp = 0;
	int p = 1;
	int c = 0;

	for (int i = 2; i <= n; i++) {
		c = p + pp;
		pp = p;
		p = c;
	}
	return c;
}


int main() {
	int n;

	scanf("%d", &n);

	printf("%d - %d\n", mrFib(n), count);
	printf("%d", iFib(n));

	return 0;
}
