#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

// 선택 정렬
void SelectionSort(int *p, int n) {
	int minLoc ,tmp;

	for (int i = 0; i < n - 1; i++) {
		minLoc = i;
		for (int j = i + 1; j < n; j++) {
			if (p[j] < p[minLoc])
				minLoc = j;
		}
		tmp = p[i];
		p[i] = p[minLoc];
		p[minLoc] = tmp;
	}
}



int main() {
	int n;
	int* list = NULL;

	scanf("%d", &n);

	list = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) 
		scanf("%d", &list[i]);
	
	SelectionSort(list, n);

	for (int i = 0; i < n; i++)
		printf(" %d", list[i]);

	return 0;
}