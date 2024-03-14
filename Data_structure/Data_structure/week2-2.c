#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int mostOnes(int **A, int n) {
	int i = 0, j = 0, row;

	while (1) {
		while (A[i][j] == 1) {
			j += 1;
			if (j == n)
				return i;
		}
		row = i;
		while (A[i][j] == 0){
			i += 1;
			if (i == n)
				return row;
		}
	}
}

int main() {
	int n;
	int** A = NULL;

	scanf("%d", &n);

	A = (int**)malloc(n * sizeof(int*));
	if (A == NULL) return -1;


	for (int i = 0; i < n; i++) {
		A[i] = (int*)malloc(n * sizeof(int));
		if (A[i] == NULL) return -1;

		for (int j = 0; j < n; j++) 
			scanf("%d", &A[i][j]);	
	}

	printf("%d", mostOnes(A, n));

	for (int i = 0; i < n; i++)
		free(A[i]);
	free(A);

	return 0;
}