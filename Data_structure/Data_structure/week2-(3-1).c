#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int* prefixAverages1(int X[], int n) {
	int* A = NULL;
	double tmp;

	A = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < i + 1; j++)
			sum += X[j];

		tmp = (double)(sum) / (i + 1) + 0.5;
		A[i] = (int)(tmp);
	}

	return A;
}

int* prefixAverages2(int X[], int n) {
	int* A = NULL;
	int sum = 0;
	double tmp;

	A = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		sum += X[i];
		tmp = (double)(sum) / (i + 1) + 0.5;
		A[i] = (int)(tmp);
	}
	return A;
}

int main() {
	int n;
	int* X = NULL, * tmp = NULL;

	scanf("%d", &n);

	X = (int*)malloc(n * sizeof(int));
	if (X == NULL) return -1;

	for (int i = 0; i < n; i++)
		scanf("%d", &X[i]);

	tmp = prefixAverages1(X, n);
	for (int i = 0; i < n; i++) 
		printf("%d ", tmp[i]);
	
	printf("\n");

	tmp = prefixAverages2(X, n);
	for (int i = 0; i < n; i++)
		printf("%d ", tmp[i]);

	free(X);
	return 0;
}