#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ���� ť -> rear = (rear + 1) % N

#define N 10

typedef char element;

typedef struct {
	element data[N];
	int front, rear;
}QueueType;

void init(QueueType* Q) {
	Q->front = Q->rear = 0;
}

int isEmpty(QueueType* Q) {
	return Q->front == Q->rear;
}

int isFull(QueueType* Q) {
	return Q->front == (Q->rear + 1) % N;
}

void enqueue(QueueType* Q, element e) {
	if (isFull(Q))
		printf("FULL.\n");
	else {
		Q->rear = (Q->rear + 1) % N;
		Q->data[Q->rear] = e;
	}
}

element dequeue(QueueType* Q) {
	if (isEmpty(Q)) {
		printf("Empty.\n");
		return 0;
	}

	Q->front = (Q->front + 1) % N;
	return Q->data[Q->front];
}

element peek(QueueType* Q) {
	if (isEmpty(Q)) {
		printf("Empty.\n");
		return 0;
	}

	return Q->data[(Q->front + 1) % N];
}

void print(QueueType* Q) {
	printf("Front : %d - Rear : %d\n", Q->front, Q->rear);

	int i = Q->front;
	while (i != Q->rear) {
		i = (i + 1) % N;
		printf("[%c] ", Q->data[i]);
	}
	printf("\n");
}

int main() {
	QueueType Q;
	init(&Q);
	srand(time(NULL));

	for (int i = 0; i < 7; i++)
		enqueue(&Q, rand() % 26 + 65);
	print(&Q); getchar();

	for (int i = 0; i < 3; i++)
		printf("[%c] ", dequeue(&Q));
	printf("\n"); print(&Q); getchar();

	return 0;
}