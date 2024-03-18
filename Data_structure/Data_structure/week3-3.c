#pragma warning(disable:4996)
#include <stdio.h>

int reverse_Digits(int n) {
	if (n / 10 == 0) 
		return printf("%d\n", n);
	else {
		printf("%d\n", n % 10);
		return reverse_Digits(n / 10);
	}
}

int main() {
	int N;

	scanf("%d", &N);

	reverse_Digits(N);

	return 0;
}