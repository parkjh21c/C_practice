#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

void selectionSort(int* num, int n) {

	for (int j = n - 1; j > 0; j--) {
		int max_index = 0;
		int tmp;
		for (int i = 1; i <= j; i++) {
			if (num[i] >= num[max_index])
				max_index = i;
		}
		tmp = num[max_index];
		num[max_index] = num[j];
		num[j] = tmp;
	}
}

int main() {
	int n;
	int* num;

	scanf("%d", &n);

	num = (int*)malloc(n * sizeof(int));
	if (num == NULL) return -1;

	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);

	selectionSort(num, n);

	for (int i = 0; i < n; i++)
		printf(" %d", num[i]);

	return 0;
}