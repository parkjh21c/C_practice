#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	int* answer = NULL, * tmp = NULL, * stack = NULL;

	scanf("%d", &n);

	// 동적할당
	answer = (int*)malloc(n * sizeof(int));
	tmp = (int*)malloc(n * sizeof(int));
	stack = (int*)malloc(n * sizeof(int));
	if (answer == NULL) return -1;
	if (tmp == NULL) return -1;
	if (stack == NULL) return -1;

	for (int i = 0; i < n; i++) {
		scanf("%d", &answer[i]);
		tmp[i] = i + 1;
	}
	

	return 0;
}