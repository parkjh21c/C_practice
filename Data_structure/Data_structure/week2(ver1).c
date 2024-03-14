#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 8

// 난수 생성

void makeArray(int A[][N]) {
	for (int i = 0; i < N; i++) {
		int cnt = rand() % 8;

		for (int j = 0; j < cnt; j++)
			A[i][j] = 1;

		for (int j = cnt; j < N; j++)
			A[i][j] = 0;
	}
}

void printArray(int A[][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf(" %2d", A[i][j]);
		printf("\n");
	}
	printf("\n");
}

int mostOnes(int A[][N], int n) {
	int i = 0, j = 0;
	int row;

	while (1) {
		while (A[i][j] == 1) {
			j += 1;
			if (j == n)
				return i;
		}
		row = i;

		while (A[i][j] == 0) {
			i += 1;
			if (i == n)
				return row;
		}
	}
}



int main() {
	int A[N][N];

	srand(time(NULL));
	makeArray(A);
	printArray(A);

	printf("%d" ,mostOnes(A, N));
	

	return 0;
}