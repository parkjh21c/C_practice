#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct Node* next;
	int data;
}Node;

void addNode(Node* hash, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->next = hash->next;
	node->data = data;
	hash->next = node;
}

int findData(Node* hash, int data) {
	int index = 0;
	Node* p = hash->next;
	for (; p != NULL; p = p->next) {
		index++;
		if (p->data == data)
			return index;
	}
	return 0;
}

int deleteData(Node* hash, int data) {
	int index = findData(hash, data);
	if (index != 0) {
		Node* p = hash, *q = hash->next;
		for (int i = 1; i < index; i++) {
			q = q->next;
			p = p->next;
		}
		p->next = q->next;
		free(q);
	}
	return index;
}

void hashPrint(Node** hash, int M) {
	for (int i = 0; i < M; i++) 
		for (Node* p = hash[i]->next; p != NULL; p = p->next) 
			printf(" %d", p->data);
	printf("\n");
}

int main() {
	int M;
	Node** hash;

	scanf("%d", &M);

	hash = (Node**)malloc(M * sizeof(Node*));

	for (int i = 0; i < M; i++) {
		hash[i] = (Node*)malloc(sizeof(Node));
		hash[i]->next = NULL;
	}

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
		else if (command == 'd') {
			scanf("%d", &data); getchar();

			int i = data % M;
			printf("%d\n", deleteData(hash[i], data));
		}
		else if (command == 'p') {
			hashPrint(hash, M);
		}
		else if (command == 'e')
			break;
	}
	return 0;
}