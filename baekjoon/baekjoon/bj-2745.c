#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main() {
	int B, total = 0, len = 0, tmp = 1;
	char N[100];

	scanf("%s %d", N, &B);

	len = strlen(N);
	

	// B가 10 미만일 경우
	if (B < 10) {
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < i; j++)
				tmp *= B;
			total += (N[len - i - 1] - '0') * tmp;
			tmp = 1;
		}
	}
	
	// B가 10을 초과할 경우
	else if (B > 10) {
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < i; j++)
				tmp *= B;
			if (N[len - i - 1] >= 'A')
				total += (N[len - i - 1] - 'A' + 10) * tmp;
			else
				total += (N[len - i - 1] - '0') * tmp;
			tmp = 1;
		}
	}

	// B가 10일 경우
	else {
		total = atoi(N);
	}

	printf("%d", total);

	return 0;
}