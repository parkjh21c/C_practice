#pragma warning(disable:4996)
#include <stdio.h>

int main() {
	int num[3], max_index;

	scanf("%d %d %d", &num[0], &num[1], &num[2]);

	if (num[0] >= num[1] + num[2]) {
		printf("%d", 2 * (num[1] + num[2]) - 1);
	}
	else if (num[1] >= num[0] + num[2]) {
		printf("%d", 2 * (num[0] + num[2]) - 1);
	}
	else if (num[2] >= num[0] + num[1]) {
		printf("%d", 2 * (num[0] + num[1]) - 1);
	}
	else {
		printf("%d", num[0] + num[1] + num[2]);
	}


	return 0;
}