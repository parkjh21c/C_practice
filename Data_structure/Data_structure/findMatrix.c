#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 8

// 난수 생성

void makeArray(int A[][N]) {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			A[i][j] = rand() % 100;
}

void printArray(int A[][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf(" %2d", A[i][j]);
		printf("\n");
	}
	printf("\n");
}

int findRow(int A[], int key) {
	for (int col = 0; col < N; col++)
		if (A[col] == key)
			return col;

	return -1;
}

void findMatrix(int A[][N], int key) {
	int row = 0;
	int col; // findrow에서 리턴값

	while (row < N) {
		col = findRow(A[row], key);

		if (col >= 0) {
			printf("key %d is in A[%d][%d].\n", key, row, col);
			return;
		}
		else
			row++;
	}

	printf("%d is not exists.\n", key);
}

int main() {
	int A[N][N];

	srand(time(NULL));
	makeArray(A);
	printArray(A);

	int key;
	printf("Input key : ");
	scanf("%d", &key);

	findMatrix(A, key);

	return 0;
}