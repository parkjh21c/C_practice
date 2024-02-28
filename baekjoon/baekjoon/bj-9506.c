#pragma warning (disable:4996)
#include <stdio.h>

int main() {
	int n, tmp = 0, count = 0;

	while (1) {
		int tm[50];

		tmp = 0;
		count = 0;

		scanf("%d", &n);

		if (n == -1)
			break;

		for (int i = 1; i <= (n / 2); i++) {
			if (n % i == 0) {
				tmp += i;
				tm[count] = i;
				count++;

				if (tmp > n) {
					break;
				}
			}
		}

		if (tmp == n) {
			printf("%d = %d", n, tm[0]);

			for (int i = 1; i < count; i++)
				printf(" + %d", tm[i]);

			printf("\n");
			
		}
		else {
			printf("%d is NOT perfect.\n", n);
		}

	}


	return 0;
}