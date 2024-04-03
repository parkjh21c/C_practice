#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef int element;

typedef struct{
	element data[N];
	int size;
}ListType;

void init(ListType* L) {
	L->size = 0;
}

int isEmpty(ListType* L) {
	return L->size == 0;
}

int isFull(ListType* L) {
	return L->size == N;
}

void insertLast(ListType* L, element e) {
	if (isFull(L))
		printf("Overflow!!\n");
	else {
		L->data[L->size] = e;
		L->size++;
	}
}

void insert(ListType* L, int pos, element e) {
	if (isFull(L)) {
		printf("Overflow!!\n");
		return;
	}
	if (pos < 0 || pos > L->size) {
		printf("Invalid Position!!\n");
		return;
	}

	for (int i = L->size - 1; i >= pos; i--)
		L->data[i + 1] = L->data[i];

	L->data[pos] = e;
	L->size++;
}

element delete(ListType* L, int pos) {
	if (isEmpty(L)) {
		printf("Underflow!!\n");
		return -1;
	}
	if (pos < 0 || pos >= L->size) {
		printf("Invalid Position!!\n");
		return -1;
	}

	element e = L->data[pos];

	for (int i = pos; i < L->size - 1; i++)
		L->data[i] = L->data[i + 1];

	L->size--;

	return e;
}

void print(ListType* L) {
	for (int i = 0; i < L->size; i++)
		printf("%d -> ", L->data[i]);
	printf("\b\b\b   \n");
}

int main() {
	ListType L;
	init(&L);

	insertLast(&L, 10); print(&L);
	insertLast(&L, 20); print(&L);
	insertLast(&L, 30); print(&L); getchar();

	insert(&L, 1, 40); print(&L);
	insert(&L, 0, 50); print(&L);
	insert(&L, 3, 60); print(&L); getchar();

	printf("[%d] is deleted.\n", delete(&L, 2)); print(&L);
	printf("[%d] is deleted.\n", delete(&L, L.size-1)); print(&L);

	return 0;
}