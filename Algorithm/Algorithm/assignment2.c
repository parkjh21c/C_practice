#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

int n = 100000;
int Limits[4] = { 1, 100, 500, 1000 };

int* createArray() {
	int* A = (int*)malloc(n*sizeof(int));

	for (int i = 0; i < n; i++)
		A[i] = rand() % n + 1;

	return A;
}

void quickSort(int* A, int n) {
	rQuickSort(A, 0, n - 1);
	if () {
		insertionSort(A, n);
	}
}

int main() {
	srand(time(NULL));
	int* A = createArray();

	for (int i = 0; i < 4; i++) {


		int* A1;
		A1 = A;
		quickSort(A1, n);
	}


	return 0;
}