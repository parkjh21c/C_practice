#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int inPlacePartition(int* arr, int left, int right, int p) {
	int pivot_val = arr[p];
	int tmp = arr[p];
	arr[p] = arr[right];
	arr[right] = tmp;

	int s = left;

	for (int i = left; i < right; i++) {
		if (arr[i] < pivot_val) {
			int temp = arr[i];
			arr[i] = arr[s];
			arr[s] = temp;
			s++;
		}
	}

	tmp = arr[right];
	arr[right] = arr[s];
	arr[s] = tmp;

	return s;
}

int findPivot(int left, int right) {
	int pivot;
	pivot = rand() % (right - left + 1) + left;
	return pivot;
}

void inPlaceQuickSort(int* arr, int left, int right) {
	if (left < right) {
		int p = findPivot(left, right);
		int a = inPlacePartition(arr, left, right, p);

		inPlaceQuickSort(arr, left, a - 1);
		inPlaceQuickSort(arr, a + 1, right);
	}
}

int main() {
	int n;
	int* arr;

	scanf("%d", &n);

	arr = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	srand(time(NULL));

	inPlaceQuickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
		printf(" %d", arr[i]);

	return 0;
}