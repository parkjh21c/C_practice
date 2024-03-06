#pragma warning(disable:4996)
#include <stdio.h>

void ABC(int a[], int k);

int main() {
	int num[10];

	for (int i = 0; i < 10; i++)
		scanf("%d", &num[i]);

	
	for (int k = 0; k < 9; k++)
		ABC(num, k);

	for (int i = 0; i < 10; i++)
		printf(" %d", num[i]);


	return 0;
}

void ABC(int a[], int k) {
	int tmp, index;

	tmp = a[k];
	index = k;

	for (int i = k + 1; i < 10; i++) {
		if (tmp < a[i]) {
			index = i;
			tmp = a[i];
		}
	}

	a[index] = a[k];
	a[k] = tmp;
}