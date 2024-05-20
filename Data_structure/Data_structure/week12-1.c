#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct {
	element* data;
	int front, rear;
	int q;
}QueueType;

void init(QueueType* Q) {
	Q->front = Q->rear = 0;
	for (int i = 0; i < Q->q; i++)
		Q->data[i] = 0;
}

int isEmpty(QueueType* Q) {
	return Q->front == Q->rear;
}

int isFull(QueueType* Q) {
	return Q->front == (Q->rear + 1) % Q->q;
}

void enqueue(QueueType* Q, element e) {
	Q->rear = (Q->rear + 1) % Q->q;
	Q->data[Q->rear] = e;
}

void dequeue(QueueType* Q) {
	Q->front = (Q->front + 1) % Q->q;
	Q->data[Q->front] = 0;
}

void print(QueueType* Q) {
	for (int i = 0; i < Q->q; i++) 
		printf(" %d", Q->data[i]);
	printf("\n");
}

int main() {
	QueueType Q;
	int n;

	scanf("%d", &Q.q);
	
	Q.data = (int*)malloc(Q.q * sizeof(int));
	init(&Q);

	scanf("%d", &n); getchar();

	for (int i = 0; i < n; i++) {
		char type;
		scanf("%c", &type); getchar();

		if (type == 'I') {
			element e;
			scanf("%d", &e); getchar();

			if (isFull(&Q)) {
				printf("overflow");
				print(&Q);
				break;
			}
			else
				enqueue(&Q, e);
		}
		else if (type == 'D') {
			if (isEmpty(&Q)) {
				printf("underflow");
				break;
			}
			else
				dequeue(&Q);
		}
		else if (type == 'P') 
			print(&Q);
		
	}

	return 0;
}