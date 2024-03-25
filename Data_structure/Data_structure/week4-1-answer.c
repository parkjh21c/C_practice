#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

void reversePosition(int x[], int start, int end) {
	int temp;

	for (int i = 0; i <= (end - start) / 2; i++) {
		temp = x[start + i];
		x[start + i] = x[end - i];
		x[end - i] = temp;
	}
}

int main() {
	int n, m, x[100];

	int start, end;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);

	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &start, &end);
		reversePosition(x, start, end);
	}

	for (int i = 0; i < n; i++)
		printf(" %d", x[i]);



	return 0;
}