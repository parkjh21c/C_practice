#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int findKey(int* arr, int key, int first, int last) {
	int mid = (last + first) / 2;
	
	if (arr[mid] == key)
		return mid;
	if (last == first == 0)
		return -1;
	if (last == first)
		return last;
	if (arr[mid] > key)
		return findKey(arr, key, first, mid - 1);
	else if (arr[mid] < key)
		return findKey(arr, key, mid + 1, last);
	
}

int main() {
	int n, k;
	int* arr;

	scanf("%d %d", &n, & k);

	arr = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	printf(" %d", findKey(arr, k, 0, n - 1));

	return 0;
}