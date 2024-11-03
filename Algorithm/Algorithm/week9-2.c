#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct Node* next;
	int data;
}Node;

int main() {
	int M, n;
	Node* hash;

	scanf("%d %d", &M, &n);

	hash = (Node*)malloc(M * sizeof(Node));



	while (1) {
		char command;
		int data;
		scanf("%c", &command);

		if (command == 'i') {
			scanf("%d", &data); getchar();

			int i = data % M;
			addNode(hash[i], data);
		}
		else if (command == 's') {
			scanf("%d", &data); getchar();

			int i = data % M;
			printf("%d\n", findData(hash[i], data));
		}
		else if (command == 'e')
			break;
	}
	return 0;
}