#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

void exchange(int X[], int a, int b) {
	int tmp;
	int n = (b - a) / 2;

	for (int i = 0; i <= n; i++) {
		tmp = X[a + i];
		X[a + i] = X[b - i];
		X[b - i] = tmp;
	}
}

int main() {
	int N, info;
	int X[100], * info_ab = NULL;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &X[i]);

	scanf("%d", &info);

	info_ab = (int*)malloc((info * 2) * sizeof(int));
	if (info_ab == NULL) return -1;

	for (int i = 0; i < info*2; i++)
		scanf("%d", &info_ab[i]);

	// chage X
	for (int i = 0; i < info*2; i+=2) 
		exchange(X, info_ab[i], info_ab[i + 1]);
	
	for (int j = 0; j < N; j++)
		printf(" %d", X[j]);

	free(info_ab);

	return 0;
}