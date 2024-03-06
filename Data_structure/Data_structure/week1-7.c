#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

int main() {
	int N;
	int* a = NULL, * b = NULL;

	scanf("%d", &N);

	a = (int*)malloc(N * sizeof(int));
	b = (int*)malloc(N * sizeof(int));
	if (a == NULL) return -1;
	if (b == NULL) return -1;

	for (int i = 0; i < N; i++) 
		scanf("%d", &a[i]);
	
	for (int i = 0; i < N; i++)
		scanf("%d", &b[i]);

	
	for (int i = 0; i < N; i++) 
		printf(" %d", a[i] + b[N - i - 1]);
	
	free(a);
	free(b);

	return 0;
}