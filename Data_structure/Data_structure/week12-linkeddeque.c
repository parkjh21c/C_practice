#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef char element;

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

void addFront(DequeType* D, element e) {
	DequeNode* node = (DequeNode*)malloc(sizeof(DequeNode));

	node->data = e;
	node->prev = node->next = D->front;

	if (isEmpty(D))
		D->front = D->rear = node;
	else {
		node->next = D->front;
		D->front->prev = node;
		D->front = node;
	}
}

void addRear(DequeType* D, element e) {
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

element deleteFront(DequeType* D) {
	if (isEmpty(D)) {
		printf("Empty.\n");
		return 0;
	}
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

element deleteRear(DequeType* D) {
	if (isEmpty(D)) {
		printf("Empty.\n");
		return 0;
	}
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

element peek(DequeType* D) {
	if (isEmpty(D)) {
		printf("Empty.\n");
		return 0;
	}

	return D->front->data;
}

void print(DequeType* D) {
	DequeNode* p;

	for (p = D->front; p != NULL; p = p->next)
		printf("[%c] => ", p->data);
	printf("NULL\n");
}

int main() {
	DequeType D;
	init(&D);
	srand(time(NULL));

	for (int i = 0; i < 4; i++)
		addRear(&D, rand() % 26 + 65);
	print(&D); getchar();

	for (int i = 0; i < 3; i++)
		printf("[%c] ", deleteFront(&D));
	printf("\n");
	print(&D); getchar();

	for (int i = 0; i< 2; i++)
		addFront(&D, rand() % 26 + 65);
	print(&D); getchar();

	for (int i = 0; i < 2; i++)
		printf("[%c] ", deleteRear(&D));
	printf("\n");
	print(&D); getchar();


	return 0;
}