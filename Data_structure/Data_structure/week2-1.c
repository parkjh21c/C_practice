#pragma warning (disable:4996)
#include <stdio.h>

// µ¡¼À »¬¼ÀÀ¸·Î¸¸ ±¸¼º
int modulo(int a, int b) {
	int sum = 0;

	while (1) {
		if (sum + b > a)
			return a - sum;
		else if (sum == a)
			return 0;
		else
			sum += b;
	}
}

int main() {
	int a, b;

	scanf("%d %d", &a, &b);

	printf("%d", modulo(a, b));

	return 0;
}