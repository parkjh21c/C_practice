#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

void matrix(int n, int mtx[][100]) {
	int row = 1, num = 1;

	for (; row <= n; row++) {
		if (row % 2 != 0) {
			for (int i = 0; i < n; i++, num++) 
				mtx[row - 1][i] = num;
		}
		else 
			for (int i = n - 1; i >= 0; i--, num++)
				mtx[row - 1][i] = num;
	}
}

int main() {
	int N;
	int mtx[100][100];

	scanf("%d", &N);

	matrix(N, mtx);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf(" %d", mtx[i][j]);
		printf("\n");
	}

	return 0;
}