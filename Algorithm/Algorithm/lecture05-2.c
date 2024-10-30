#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

void insertionSort(int* num, int n) {
	for (int i = 1; i < n; i++) {
		int index = i;
		int tmp = num[i];
		for (int j = 0; j < i; j++) {
			if (num[j] > num[i]) {
				index = j;
				break;
			}
		}
		for (int j = i - 1; j >= index; j--) 
			num[j + 1] = num[j];
		
		num[index] = tmp;
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

	insertionSort(num, n);

	for (int i = 0; i < n; i++)
		printf(" %d", num[i]);

	return 0;
}