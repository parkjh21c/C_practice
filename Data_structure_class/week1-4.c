#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

int main() {
	char ch[101];

	scanf("%s", ch);

	for (int i = 0; i < strlen(ch); i++) {
		char tmp[101];
		int count = 0;

		for (int j = i; j < strlen(ch); j++, count++) {
			tmp[count] = ch[j];
		}
		tmp[count] = '\0';

		strncat(tmp, ch, i);

		printf("%s\n", tmp);
	}


	return 0;
}