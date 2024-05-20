#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct QueueNode {
	element data;
	struct QueueNode* next;
}QueueNode;

typedef struct {
	QueueNode* front;
	QueueNode* rear;
}QueueType;

void init(QueueType* Q) {
	Q->front = Q->rear = NULL;
}

int isEmpty(QueueType* Q) {
	return Q->front == NULL;
}

void enqueue(QueueType* Q, element e) {
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));

	node->data = e;
	node->next = NULL;
	
	if (isEmpty(Q))
		Q->front = Q->rear = node;
	else {
		Q->rear->next = node;
		Q->rear = node;
	}
}

element dequeue(QueueType* Q) {
	if (isEmpty(Q)) {
		printf("Empty.\n");
		return 0;
	}
	QueueNode* p = Q->front;
	element e = p->data;
	Q->front = p->next;
	free(p);

	return e;
}

element peek(QueueType* Q) {
	if (isEmpty(Q)) {
		printf("Empty.\n");
		return 0;
	}

	return Q->front->data;
}

void print(QueueType* Q) {
	QueueNode* p;

	for (p = Q->front; p != NULL; p = p->next)
		printf("[%c] => ", p->data);
	printf("NULL\n");
}

int main() {
	QueueType Q;
	init(&Q);
	
	enqueue(&Q, 'A');
	enqueue(&Q, 'T');
	enqueue(&Q, 'C');
	print(&Q);

	printf("%c\n", dequeue(&Q));
	printf("%c\n", dequeue(&Q));
	printf("%c\n", peek(&Q));
	print(&Q);


	return 0;
}