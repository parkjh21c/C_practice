#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int H[100];	// 赛
int n = 0;	// 赛狼 农扁

void upHeap(int i) {
	int tmp;

	if (i == 1)
		return;
	else if (H[i] <= H[i / 2])
		return;

	tmp = H[i / 2];
	H[i / 2] = H[i];
	H[i] = tmp;
	upHeap(i / 2);
}

// 火涝
void insertItem(int key) {
	n++;
	H[n] = key;
	upHeap(n);
	printf("0\n");
}

void downHeap(int i) {
	int tmp, bigger;

	bigger = 2 * i;
	if (bigger > n)
		return;
	else if (H[bigger] <= H[i] && H[bigger + 1] <= H[i])
		return;
	else if (bigger + 1 <= n && H[bigger + 1] > H[bigger])
		bigger += 1;

	tmp = H[i];
	H[i] = H[bigger];
	H[bigger] = tmp;
	downHeap(bigger);
}

// 昏力
int removeMax() {
	int key;

	key = H[1];
	H[1] = H[n];
	n--;

	downHeap(1);
	return key;
}

void printHeap() {
	for (int i = 1; i < n + 1; i++)
		printf(" %d", H[i]);
	printf("\n");
}

int main() {
	char command;
	int key;

	while (1) {
		scanf("%c", &command);

		if (command == 'i') {
			scanf("%d", &key);
			insertItem(key);
		}
		else if (command == 'd') {
			key	= removeMax();
			printf("%d\n", key);
		}

		else if (command == 'p')
			printHeap();

		else if (command == 'q')
			break;
	}

	return 0;
}