#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

void changeOrder(int x[], int m) {
	int start, tmp1, tmp2, next;

	scanf("%d", &start);
	tmp1 = x[start];

	for (int i = 0; i < m - 1; i++) {
		scanf("%d", &next);
		tmp2 = x[next];
		x[next] = tmp1;
		tmp1 = tmp2;
	}
}

int main() {
	int N, M, X[100];

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &X[i]);

	scanf("%d", &M);

	changeOrder(X, M);
	
	for (int i = 0; i < N; i++)
		printf(" %d", X[i]);

	return 0;
}