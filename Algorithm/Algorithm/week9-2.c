#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int M;

int addId(int* hash, int data, int index) {
	for (; index < M; index++) {
		if (hash[index] == 0) {
			hash[index] = data;
			return index;
		}
		printf("C");
	}
	return addId(hash, data, 0);
}

int searchId(int* hash, int data, int index) {
	int i = index;
	for (; i < M; i++) 
		if (hash[i] == data)
			return i;

	for (int j = 0; j < index; j++)
		if (hash[j] == data)
			return j;
	
	return -1;
}

int main() {
	int n;
	int* hash;

	scanf("%d %d", &M, &n); getchar();

	hash = (int*)malloc(M * sizeof(int));
	for (int i = 0; i < M; i++)
		hash[i] = 0;

	while (1) {
		char command;
		int data;
		scanf("%c", &command);

		if (command == 'e')
			break;

		scanf("%d", &data); getchar();

		int i = data % M;
		if (command == 'i') 
			printf("%d\n",addId(hash, data, i));
		
		else if (command == 's') {
			int s = searchId(hash, data, i);
			if (s == -1)
				printf("%d\n", s);
			else
				printf("%d %d\n", s, data);
		}
	}
	return 0;
}