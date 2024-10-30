#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int findPivot(int left, int right) {
	int pivot;
	pivot = rand() % (right - 1) + left + 1;
	return pivot;
}

void inPlaceQuickSort(int* arr, int left, int right) {
	if (left < right) {
		int p = findPivot(left, right);
		int a = 
	}
}

int main() {
	int n;
	int* arr;

	scanf("%d", &n);

	arr = (int*)malloc(n * sizeof(int));
	if (arr == NULL) return -1;

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	srand(time(NULL));

	inPlaceQuickSort(arr, 0, n - 1);

	return 0;
}