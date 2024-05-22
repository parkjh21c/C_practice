#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;

typedef struct DequeNode {
	element data;
	struct DequeNode* prev;
	struct DequeNode* next;
}DequeNode;

typedef struct {
	DequeNode* front;
	DequeNode* rear;
}DequeType;

void init(DequeType* D) {
	D->front = D->rear = NULL;
}

int isEmpty(DequeType* D) {
	return D->front == NULL;
}

void add_front(DequeType* D, element e) {
	DequeNode* node = (DequeNode*)malloc(sizeof(DequeNode));
	
	node->data = e;
	node->prev = node->next = NULL;

	if (isEmpty(D))
		D->front = D->rear = node;
	else {
		node->next = D->front;
		D->front->prev = node;
		D->front = node;
	}
}

void add_rear(DequeType* D, element e) {
	DequeNode* node = (DequeNode*)malloc(sizeof(DequeNode));

	node->data = e;
	node->prev = node->next = NULL;

	if (isEmpty(D))
		D->front = D->rear = node;
	else {
		node->prev = D->rear;
		D->rear->next = node;
		D->rear = node;
	}
}

element delete_front(DequeType* D) {
	DequeNode* p = D->front;
	element e = p->data;

	D->front = p->next;
	
	if (D->front == NULL)
		D->rear = NULL;
	else
		D->front->prev = NULL;

	free(p);

	return e;
}

element delete_rear(DequeType* D) {
	DequeNode* p = D->rear;
	element e = p->data;

	D->rear = p->prev;

	if (D->rear == NULL)
		D->front = NULL;
	else
		D->rear->next = NULL;

	free(p);

	return e;
}

void print(DequeType* D) {
	DequeNode* p;

	for (p = D->front; p != NULL; p = p->next)
		printf(" %d", p->data);
	printf("\n");
}

int main() {
	DequeType D;
	init(&D);
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		char ch[4];
		scanf("%s", ch);

		// add_front
		if (strcmp(ch, "AF") == 0) {
			element e;
			scanf("%d", &e);

			add_front(&D, e);
		}

		// add_rear
		else if (strcmp(ch, "AR") == 0) {
			element e;
			scanf("%d", &e);

			add_rear(&D, e);
		}

		// delete_front
		else if (strcmp(ch, "DF") == 0) {
			if (isEmpty(&D)) {
				printf("underflow");
				break;
			}
			delete_front(&D);
		}

		// delete_rear
		else if (strcmp(ch, "DR") == 0) {
			if (isEmpty(&D)) {
				printf("underflow");
				break;
			}
			delete_rear(&D);
		}

		else if (strcmp(ch, "P") == 0) {
			print(&D);
		}
	}
	

	return 0;
}