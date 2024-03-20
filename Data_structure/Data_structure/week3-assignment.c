#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>

int count;
// memoization

int mrFib(int n, int Fib[]) {
	count++;
	if (n <= 1)
		return n;
	else if (Fib[n] != 0)
		return Fib[n];
	else {
		Fib[n] = mrFib(n - 1, Fib) + mrFib(n - 2, Fib);
		return Fib[n];
	}
}


int main() {
	int n;
	int* Fib = NULL;

	scanf("%d", &n);

	Fib = (int*)malloc((n + 1) * sizeof(int));
	if (Fib == NULL) return -1;

	for (int i = 0; i <= n; i++)
		Fib[i] = 0;

	printf("%d - %d", mrFib(n, Fib), count);
	
	free(Fib);

	return 0;
}