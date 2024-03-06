#pragma warning(disable:4996)
#include <stdio.h>

int sum(int n);

int main() {
	int X, total = 0;

	scanf("%d", &X);

	for (int i = 1; i <= X; i++) 
		total += sum(i);
	
	printf("%d", total);

	return 0;
}

int sum(int n) {
	int total = 0;

	for (int i = 1; i <= n; i++)
		total += i;

	// total = (n * (n + 1)) / 2 로 표현 가능 -> 반복문 줄일 수 있음

	return total;
}