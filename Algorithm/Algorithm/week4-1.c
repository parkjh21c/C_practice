#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int H[100];
int n = 0;

void downHeap(int i) {
	int tmp, bigger;

	bigger = 2 * i;
	if (bigger > n)
		return;
	else if (bigger == n) {
		if (H[bigger] < H[i])
			return;
	}
	else if (bigger + 1 <= n) {
		if (H[bigger] < H[i] && H[bigger + 1] < H[i])
			return;
		if (H[bigger + 1] > H[bigger])
			bigger += 1;
	}
	
	tmp = H[bigger];
	H[bigger] = H[i];
	H[i] = tmp;
	downHeap(bigger);
}

void rBuildHeap(int i) {
	if (i > n)
		return;
	rBuildHeap(2 * i);
	rBuildHeap(2 * i + 1);
	downHeap(i);
}

void buildHeap() {
	for (int i = n / 2; i >= 1; i--)
		downHeap(i);
}

void printArray() {
	for (int i = 1; i <= n; i++)
		printf(" %d", H[i]);
	printf("\n");
}

void inPlaceHeapSort() {
	int m;
	m = n;
	for (int i = m; i >= 2; i--) {
		int tmp;
		tmp = H[1];
		H[1] = H[i];
		H[i] = tmp;
		n -= 1;

		rBuildHeap(1);
	}
	n = m;
}



int main() {

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &H[i]);

	rBuildHeap(1);
	inPlaceHeapSort();
	printArray();
	return 0;
}