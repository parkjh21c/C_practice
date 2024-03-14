#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void makeArray(int X[], int n) {
	for (int i = 0; i < n; i++) {
		int cnt = rand() % 10001;

		X[i] = cnt;
	}

}


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
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;

	int n;
	int* X = NULL, * tmp = NULL;

	srand(time(NULL));
	QueryPerformanceFrequency(&ticksPerSec);

	scanf("%d", &n);

	X = (int*)malloc(n * sizeof(int));
	if (X == NULL) return -1;

	// make rand Array
	makeArray(X, n);

	// prefix1
	QueryPerformanceCounter(&start);
	tmp = prefixAverages1(X, n);
	QueryPerformanceCounter(&end);
	
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%.12fms\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

	// prefix2
	QueryPerformanceCounter(&start);
	tmp = prefixAverages2(X, n);
	QueryPerformanceCounter(&end);
	
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%fms\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

	// end of pointer
	free(X);

	return 0;
}