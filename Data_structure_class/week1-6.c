#pragma warning (disable:4996)
#include <stdio.h>

struct student {
	char name[10];
	int score;
};

int main() {
	struct student st[5];
	int sum = 0;

	for (int i = 0; i < 5; i++) {
		scanf("%s %d", st[i].name, &st[i].score);
		sum += st[i].score;
	}

	sum = sum / 5;

	for (int i = 0; i < 5; i++) {
		if (st[i].score <= sum) 
			printf("%s\n", st[i].name);
		
	}


	return 0;
}