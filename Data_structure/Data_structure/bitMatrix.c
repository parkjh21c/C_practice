#pragma warning(disable:4996)
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


int main() {
	int A[N][N];

	srand(time(NULL));
	makeArray(A);
	printArray(A);


	return 0;
}