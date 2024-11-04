#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int M, q;

int searchId(int* hash, int data, int index) {
	int h = q - data % q;
	int i, j = 0;
	while (j < M) {
		i = (index + j * h) % M;
		if (hash[i] == data)
			return i;
		j++;
	}
	return -1;
}

int addId(int* hash, int data, int index) {
	int h = q - data % q;
	int i, j = 0;
	while (1) {
		i = (index + j * h) % M;
		if (hash[i] == 0) {
			hash[i] = data;
			return i;
		}
		printf("C");
		j++;
	}
}

void printHash(int* hash) {
	for (int i = 0; i < M; i++)
		printf(" %d", hash[i]);
	printf("\n");
}

int main() {
	int n;
	int* hash;

	scanf("%d %d %d", &M, &n, &q); getchar();

	hash = (int*)malloc(M * sizeof(int));
	for (int i = 0; i < M; i++)
		hash[i] = 0;

	while (1) {
		char command;
		int data;
		scanf("%c", &command);
		
		if (command == 'i') {
			scanf("%d", &data); getchar();

			int i = data % M;
			printf("%d\n", addId(hash, data, i));
		}
		else if (command == 's') {
			scanf("%d", &data); getchar();

			int i = data % M;
			int s = searchId(hash, data, i);
			if (s == -1)
				printf("%d\n", s);
			else
				printf("%d %d\n", s, data);
		}
		else if (command == 'p')
			printHash(hash);
		else if (command == 'e') {
			printHash(hash);
			break;
		}
	}
	return 0;
}