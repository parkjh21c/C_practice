#pragma warning(disable:4996)
#include <stdio.h>

int printDigits(int n) {
	if (n / 10 == 0)
		return printf("%d\n", n);
	else {
		printDigits(n / 10);
		return printf("%d\n", n % 10);
	}
}

int main() {
	int N;

	scanf("%d", &N);

	printDigits(N);

	return 0;
}