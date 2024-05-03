#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void input(char** ch, int i) {
	char tmp[501];
	scanf("%s", tmp);
	ch[i] = (char*)malloc((strlen(tmp) + 1) * sizeof(char));

	strcpy(ch[i], tmp);
}

int cmp(char** A, char* B, int size_A) {
	int count = 0;

	for (int i = 0; i < size_A; i++) 
		if (strcmp(A[i], B) == 0) 
			return 1;

	return 0;
}

int main() {
	int N, M, count = 0;
	char** ch_N;

	scanf("%d %d", &N, &M);

	ch_N = (char**)malloc(N * sizeof(char*));

	for (int i = 0; i < N; i++) 
		input(ch_N, i);

	for (int i = 0; i < M; i++) {
		char tmp[500];
		scanf("%s", tmp);
		count += cmp(ch_N, tmp, N);
	}
	
	printf("%d", count);

	return 0;
}