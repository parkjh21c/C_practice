#pragma warning(disable:4996)
#include <stdio.h>

// xÀÇ nÁ¦°ö ±¸ÇÏ±â
// O(n)
int iPower(int x, int n) {
	int result = 1;

	for (int i = 1; i <= n; i++)
		result *= x;

	return result;
}

// Àç±Í
/*
rP(x,n) = rP(x*x, n/2) -> n is even
		= x * rP(x*x, (n - 1) / 2) -> n is odd

n = 2^k
log2 n = log2 2^k
k = log2 n


*/
int rPower(int x, int n) {
	if (n == 0)
		return 1;
	else if (n % 2 == 0)
		return rPower(x * x, n / 2);
	else
		return x * rPower(x * x, (n - 1) / 2);
}

int main() {
	int x, n;

	scanf("%d %d", &x, &n);

	printf("%d - %d", iPower(x, n), rPower(x, n));

	return 0;
}