#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

int main() {
	int N, B;
	char total[100], tmp[100];

	scanf("%d %d", &N, &B);

	total[0] = '\0';

	while (1) {
		if (N % B < 10) {
			tmp[0] = N % B + '0';
			tmp[1] = '\0';
			strcat(tmp, total);
			strcpy(total, tmp);
		}

		else {
			tmp[0] = N % B + 'A' - 10;
			tmp[1] = '\0';
			strcat(tmp, total);
			strcpy(total, tmp);
		}

		N = N / B;
		
		if (N == 0)
			break;
	}

	printf("%s", total);

	return 0;
}