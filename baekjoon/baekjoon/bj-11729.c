#pragma warning (disable:4996)
#include <stdio.h>
#include <math.h>

void Hanoi(int n, int from, int tmp, int to) {
	if (n == 1) {
		printf("%d %d\n", from, to);
	}
	else {
		Hanoi(n - 1, from, to, tmp);
		printf("%d %d\n", from, to);
		Hanoi(n - 1, tmp, from, to);
	}
}

int main() {
	int n, k;

	scanf("%d", &n);
	k = pow(2, n) - 1;
	printf("%d\n",k);
	Hanoi(n, 1, 2, 3);

	return 0;
}