#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int H[100];
int n = 0;

void upHeap(int index) {
	if (index == 1)
		return;
	int tmp;
	if (H[index] > H[index / 2]) {
		tmp = H[index];
		H[index] = H[index / 2];
		H[index / 2] = tmp;
		upHeap(index / 2);
	}
}

void downHeap(int index) {
	int tmp, bigger;

	bigger = 2 * index;
	if (bigger > n)
		return;
	else if (H[bigger] <= H[index] && H[bigger + 1] <= H[index])
		return;
	else if (bigger + 1 <= n && H[bigger + 1] > H[bigger])
		bigger += 1;

	tmp = H[index];
	H[index] = H[bigger];
	H[bigger] = tmp;
	downHeap(bigger);
}

void insertItem(int key) {
	n++;
	H[n] = key;
	upHeap(n);
}

int removeMax() {
	int tmp = H[1];
	H[1] = H[n];
	H[n] = tmp;
	n--;
	downHeap(1);
	
	return tmp;
}

void printHeap() {
	for (int i = 1; i <= n; i++)
		printf(" %d", H[i]);
	printf("\n");
}

int main() {
	while (1) {
		char p;
		int key;
		scanf("%c", &p);

		if (p == 'i') {
			scanf("%d", &key); getchar();
			insertItem(key);
			printf("0\n");
		}
		else if (p == 'd') {
			int k;
			k = removeMax();
			printf("%d\n", k);
		}
		else if (p == 'p') {
			printHeap();
		}
		else if (p == 'q')
			break;
	}

	return 0;
}
