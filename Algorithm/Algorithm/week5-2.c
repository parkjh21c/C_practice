#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct value {
	int a;
	int b;
}value;

int findPivot(int* L, int f, int r) {
	int k;
	srand(time(NULL));
	
	k = rand() % (r - 1) + f + 1;

	return k;
}

value inPlacePartition(int* L, int f, int r, int k) {
	int tmp;
	int p = L[k];

	tmp = L[k];
	L[k] = L[r];
	L[r] = tmp;

	int i = f, j = r - 1;

	while (i <= j) {
		while (i <= j && L[i] < p)
			i += 1;
		while (i <= j && L[j] > p)
			j -= 1;
		if (i < j) {
			tmp = L[i];
			L[i] = L[j];
			L[j] = tmp;
		}
	}
	tmp = L[i];
	L[i] = L[r];
	L[r] = tmp;


}

void inPlaceQuickSort(int* L, int f, int r) {

}

int main() {
	int n;

	scanf("%d", &n);

	int* L = NULL;
	L = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
		scanf("%d", &L[i]);



	for (int i = 0; i < n; i++)
		printf(" %d", L[i]);

	return 0;
}