#pragma warning(disable:4996)
#include <stdio.h>

// ����Լ�
int sum(int n) {
	if (n == 1)
		return 1;
	else
		return n + sum(n - 1);
}

int main() {
	int N;

	scanf("%d", &N);

	printf("%d",sum(N));

	return 0;
}