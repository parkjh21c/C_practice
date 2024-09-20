#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

// »ðÀÔ Á¤·Ä
void InsertionSort(int* p, int n) {
	int j, save;

	for (int i = 1; i < n; i++) {
		save = p[i];
		j = i - 1;
		while ((j >= 0) && (p[j] > save)) {
			p[j + 1] = p[j];
			j = j - 1;
		}
		p[j + 1] = save;
	}
}



int main() {
	int n;
	int* list = NULL;

	scanf("%d", &n);

	list = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
		scanf("%d", &list[i]);

	InsertionSort(list, n);

	for (int i = 0; i < n; i++)
		printf(" %d", list[i]);

	return 0;
}