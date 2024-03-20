#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int gcd1(int a, int b) {
	int r;

	while (b > 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int gcd2(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd2(b, a % b);
}

int gcd3(int a, int b) {
	while (a != b) {
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}

int gcd4(int a, int b) {
	// 순환문으로 3번 작성
	if (a == b)
		return a;
	else if (a > b)
		return gcd4(a - b, b);
	else
		return gcd4(a, b - a);
}

int main() {
	int a, b;

	scanf("%d %d", &a, &b);
	printf("GCD : %d - %d - %d", gcd1(a, b), gcd2(a, b));
	printf("GCD2 : %d - %d", gcd3(a, b), gcd4(a, b));
}