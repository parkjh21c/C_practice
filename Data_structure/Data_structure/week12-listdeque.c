#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ¿øÇü Å¥ -> rear = (rear + 1) % N

#define N 15

typedef char element;

typedef struct {
	element data[N];
	int front, rear;
}Deque;

void init(Deque* D) {
	D->front = D->rear = 0;
}

int isEmpty(Deque* D) {
	return D->front == D->rear;
}

int isFull(Deque* D) {
	return D->front == (D->rear + 1) % N;
}

void addFront(Deque* D, element e) {
	if (isFull(D))
		printf("FULL.\n");
	else {
		D->data[D->front] = e;
		D->front = (D->front - 1 + N) % N;
	}
}

void addRear(Deque* D, element e) {
	if (isFull(D))
		printf("FULL.\n");
	else {
		D->rear = (D->rear + 1) % N;
		D->data[D->rear] = e;
	}
}

element deleteFront(Deque* D) {
	if (isEmpty(D)) {
		printf("Empty.\n");
		return 0;
	}

	D->front = (D->front + 1) % N;
	return D->data[D->front];
}

element deleteRear(Deque* D) {
	if (isEmpty(D)) {
		printf("Empty.\n");
		return 0;
	}

	int pos = D->rear;
	D->rear = (D->rear - 1 + N) % N;
	return D->data[pos];
}

element peek(Deque* D) {
	if (isEmpty(D)) {
		printf("Empty.\n");
		return 0;
	}

	return D->data[(D->front + 1) % N];
}

void print(Deque* D) {
	printf("Front : %d - Rear : %d\n", D->front, D->rear);

	int i = D->front;
	while (i != D->rear) {
		i = (i + 1) % N;
		printf("[%c] ", D->data[i]);
	}
	printf("\n");
}

int main() {
	Deque D;
	init(&D);
	srand(time(NULL));

	for (int i = 0; i < 7; i++)
		addRear(&D, rand() % 26 + 65);
	print(&D); getchar();

	addFront(&D, rand() % 26 + 65);
	print(&D); getchar();

	for (int i = 0; i < 3; i++)
		printf("[%c] ", deleteFront(&D));
	printf("\n"); print(&D); getchar();

	printf("[%c]\n", deleteRear(&D));
	print(&D);

	return 0;
}