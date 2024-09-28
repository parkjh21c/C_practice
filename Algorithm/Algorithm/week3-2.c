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
	else if (H[bigger] <= H[i] && H[bigger + 1] <= H[i])
		return;
	else if (bigger + 1 <= n && H[bigger + 1] > H[bigger])
		bigger += 1;

	tmp = H[i];
	H[i] = H[bigger];
	H[bigger] = tmp;
	downHeap(bigger);
}

void printHeap() {
	for (int i = 1; i < n + 1; i++)
		printf(" %d", H[i]);
	printf("\n");
}

// Àç±Í ¹æ½Ä »óÇâ½Ä Èü
void rBuildHeap(int i) {
	if (i > n)
		return;

	rBuildHeap(2 * i);
	rBuildHeap(2 * i + 1);
	downHeap(i);
}

// ºñÀç±Í ¹æ½Ä »óÇâ½Ä Èü
void bulidHeap() {
	for (int i = n / 2; i >= 1; i--)
		downHeap(i);
}

int main() {

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &H[i]);
	rBuildHeap(1);
	printHeap();

	return 0;
}