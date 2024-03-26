#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

void changeOrder(int x[], int n, int m) {
	int temp1, temp2, idx;

	scanf("%d", &idx);
	temp1 = x[idx];

	for (int i = 0; i < m - 1; i++) {
		scanf("%d", &idx);
		temp2 = x[idx];
		x[idx] = temp1;
		temp1 = temp2;
	}
}

int main() {


	return 0;
}