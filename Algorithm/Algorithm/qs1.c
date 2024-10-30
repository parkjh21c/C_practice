#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int inPlacePartition(int* arr, int left, int right, int pivot) {
	int pivot_value = arr[pivot];

}

int findPivot(int left, int right) {
	return rand() % (right - left + 1) + left;
}

void inPlaceQuickSort(int* arr, int left, int right) {
	if (left < right) {
		int p = findPivot(left, right);
		int a = inPlacePartition(arr, left, right, p);
	}
}

int main() {
	int n;
	int* arr;

	scanf("%d", &n);

	arr = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	srand(time(NULL))

	inPlaceQuickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
		printf(" %d", arr[i]);
	
	return 0;
}