#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int MAX = 23;
int* H;
// h = x % MAX
// h' = q - x % q (q = MAX / 2)

int findElement(int k) {
	int h = k % MAX;
	int q = MAX / 2;
	int h1 = q - k % q;

	for (int i = 0; i < MAX; i++) {
		int index = (h + i * h1) % MAX;
		if (H[index] == -1) return index;
		if (H[index] == k) 
			return index;
	}
	return -1; // NoSuchKey
}

void insertItem(int k) {
	int index = findElement(k);

	if (index == -1) {
		printf("해시테이블이 만원입니다!\n");
		return;
	}

	if (H[index] != -1) {
		printf("중복키 입니다!\n");
		return;
	}
	else 
		H[index] = k;
}

int removeElement(int k) {
	int index = findElement(k);

	if (index == -1)
		return -1;
	else if (H[index] == -1)
		return -1;
	else {
		int element = H[index];
		H[index] = -1;
		return element;
	}
}

void printHashTable() {
	for (int i = 0; i < MAX; i++) 
		printf(" %d", i);
	printf("\n");
	for (int i = 0; i < MAX; i++) {
		if (H[i] == -1) printf(" .");
		else printf(" %d", H[i]);
	}
	printf("\n");
}

int main() {
	H = (int*)malloc(MAX * sizeof(int));

	for (int i = 0; i < MAX; i++)
		H[i] = -1;

	while (1) {
		char cmd;
		int k;
		scanf("%c", &cmd); getchar();

		switch (cmd){
		case 'f':
			scanf("%d", &k); getchar();
			k = findElement(k);
			if (k == -1 || H[k] == -1) printf("NoSuchKey\n");
			else printf("%d\n", H[k]);
			break;

		case 'i':
			scanf("%d", &k); getchar();
			insertItem(k);
			break;

		case 'r':
			scanf("%d", &k); getchar();
			k = removeElement(k);
			if (k == -1) printf("NoSuchKey\n");
			else printf("%d\n", k);
			break;

		case 'p':
			printHashTable();
			break;

		case 'q':
			return 0;
		default:
			break;
		}

	}

	return 0;
}