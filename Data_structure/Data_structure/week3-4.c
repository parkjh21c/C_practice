#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int max_s(int* s, int n) {
	if (n == 1) 
		return s[n - 1];
	return (max_s(s, n - 1) > s[n - 1]) ? (max_s(s, n - 1)) : (s[n - 1]);
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