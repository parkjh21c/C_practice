#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int count_str(char ch[], char c) {
	int count = 0;
	if (*ch == '\0')
		return count;
	else if (*ch == c) {
		count += count_str(ch + 1, c) + 1;
		return count;
	}
	else {
		count += count_str(ch + 1, c);
		return count;
	}
}

int main() {
	char ch[101], check;

	scanf("%s", ch); getchar();
	scanf("%c", &check);

	printf("%d", count_str(ch, check));

	return 0;
}