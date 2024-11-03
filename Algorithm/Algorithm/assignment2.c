#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

int n = 100000;
int Limits[4] = { 1, 100, 500, 1000 };
int Limit;
int mode;

int* createArray() {
	int* A = (int*)malloc(n*sizeof(int));

	for (int i = 0; i < n; i++)
		A[i] = rand() % n + 1;

	return A;
}

void inPlacePartition(int* A, int l, int r, int k, int*a, int*b) {
	int pivot_value = A[k];

	int i = l;
	int j = r;

	while (i <= j) {
		while (A[i] < pivot_value)
			i = i + 1;
		while (A[j] > pivot_value)
			j = j - 1;
		if (i <= j) {
			int tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
			i++;
			j--;
		}
	}
	*a = j;
	*b = i;
}

int findIndexOfMedianOfTree(int *A, int a, int b, int c) {
	if ((A[b] <= A[a] && a <= A[c]) || (A[c] <= A[a] && A[a] <= A[b]))
		return a;
	else if ((A[a] <= A[b] && A[b] <= A[c]) || (A[c] <= A[b] && A[b] <= A[a]))
		return b;
	else
		return c;
}

int findPivot(int* A, int l, int r) {
	if (mode == 0)
		return r;
	if (mode == 2)
		return rand() % (r - l + 1) + l;
	if (r - l == 1)
		return l;
	
	int a, b, c;
	if (mode == 1) 
		a = l, b = (l + r) / 2, c = r;
		
	else {
		a = rand() % (r - l + 1) + l;
		b = rand() % (r - l + 1) + l;
		c = rand() % (r - l + 1) + l;
	}

	return findIndexOfMedianOfTree(A, a, b, c);
	
}

void rQuickSort(int* A, int l, int r) {
	if (r - l >= Limit) {
		int k = findPivot(A, l, r);
		int a, b;
		inPlacePartition(A, l, r, k, &a, &b);
		rQuickSort(A, l, a);
		rQuickSort(A, b, r);
	}
}

void insertionSort(int* A, int n) {
	for (int i = 1; i < n; i++) {
		int key = A[i];
		int j = i - 1;

		while (j >= 0 && A[j] > key) {
			A[j + 1] = A[j];
			j = j - 1;
		}
		A[j + 1] = key;
	}
}

void quickSort(int* A, int n) {
	rQuickSort(A, 0, n - 1);
	if (Limit > 1) 
		insertionSort(A, n);
}

int main() {
	srand(time(NULL));
	int* A = createArray();

	char* modes[] = { "deterministic1", "deterministic3", "randomized1", "randomized3" };

	printf("Limit\t");
	for (int i = 0; i < 4; i++)
		printf("%s\t ", modes[i]);
	printf("\n");

	
	for (int i = 0; i < 4; i++) {
		Limit = Limits[i];
		printf("%d\t", Limit);
		
		for (int j = 0; j < 4; j++) {
			LARGE_INTEGER ticksPerSec;
			LARGE_INTEGER start, end, diff;

			QueryPerformanceFrequency(&ticksPerSec);
			QueryPerformanceCounter(&start);

			mode = j;
			
			int* A1 = (int*)malloc(n * sizeof(int));
			for (int j = 0; j < n; j++) A1[j] = A[j];
			quickSort(A1, n);

			QueryPerformanceCounter(&end);
			diff.QuadPart = end.QuadPart - start.QuadPart;
			double t = (double)diff.QuadPart / (double)ticksPerSec.QuadPart;
			printf("%.8f\t", t);
			free(A1);
		}
		printf("\n");
	}
	free(A);
	
	return 0;
}