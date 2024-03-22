#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int max_s(int* s, int n) {
	
	
}

int main() {
	int N;
	int* num = NULL;

	scanf("%d", &N);

	num = (int*)malloc(N * sizeof(int));
	if (num == NULL) return -1;

	for (int i = 0; i < N; i++)
		scanf("%d", &num[i]);

	printf("%d", max_s(num, N));

	free(num);

	return 0;
}