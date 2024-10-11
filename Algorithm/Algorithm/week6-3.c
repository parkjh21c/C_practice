#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>


int main() {
	int a, b, n;

	scanf("%d %d %d", &a, &b, &n); getchar();

	for (int i = 0; i < n; i++) {
		char bo;
		scanf("%c", &bo); 

		int m = (a + b) / 2;

		// k > m ?
		if (bo == 'Y') {
			a = m + 1;
		}
		else {
			b = m;
		}
	}
	printf("%d", b);
	return 0;
}