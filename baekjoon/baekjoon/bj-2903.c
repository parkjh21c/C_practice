#pragma warning(disable:4996)
#include <stdio.h>

int main() {
	int N, k = 1, total = 3;

	scanf("%d", &N);

	for (int i = 1; i < N; i++) {
		k *= 2;
		total += k;
	}
	
	total = total * total;

	printf("%d", total);


	return 0;
}