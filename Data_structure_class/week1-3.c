#pragma warning(disable:4996)
#include <stdio.h>

void swap(int* a, int* b);

int main() {
	int N, num[50], a, b;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &num[i]);

	scanf("%d %d", &a, &b);

	swap(&num[a], &num[b]);

	for (int i = 0; i < N; i++)
		printf(" %d", num[i]);

	return 0;
}

void swap(int* a, int* b) {
	int tmp;

	// int tmp = *a �� �����ص� ��
	tmp = *a;
	*a = *b;
	*b = tmp;

}