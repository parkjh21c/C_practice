#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct DListNode {
	element data;
	struct DListNode* prev;
	struct DListNode* next;
}DListNode;

void init(DListNode* H, DListNode* T) {
	H->next = T;
	T->prev = H;
}

// 헤드 포인터 함수는 insertFirst함수가 없으면 p를 포인터에 둘 수 없다

void insert(DListNode* H, int pos, element e) {
	DListNode* p = H;

	for (int i = 1; i < pos; i++)
		p = p->next;

	DListNode* node = (DListNode*)malloc(sizeof(DListNode));

	node->data = e;
	node->prev = p;
	node->next = p->next;

	p->next->prev = node;
	p->next = node;
}

// delete 함수 구현해볼것
element delete(DListNode* H, int pos) {
	DListNode* p = H;

	for (int i = 1; i <= pos; i++) // 삭제 되는 노드
		p = p->next;

	element e = p->data;

	p->prev->next = p->next;
	p->next->prev = p->prev;

	free(p);

	return e;
}

void print(DListNode* H, DListNode* T) {
	for (DListNode* p = H->next; p != T; p = p->next)
		printf("[%d] <=> ", p->data);
	printf("\b\b\b\b   \n");
}

int main() {
	DListNode* H = (DListNode*)malloc(sizeof(DListNode));
	DListNode* T = (DListNode*)malloc(sizeof(DListNode));

	init(H, T);

	insert(H, 1, 10); print(H, T);
	insert(H, 1, 30); print(H, T);
	insert(H, 2, 20); print(H, T);
	insert(H, 3, 40); print(H, T);
	insert(H, 4, 50); print(H, T);
	insert(H, 2, 90); print(H, T);

	printf("[%d] is deleted.\n", delete(H, 5)); print(H, T);
	printf("[%d] is deleted.\n", delete(H, 3)); print(H, T);
	printf("[%d] is deleted.\n", delete(H, 4)); print(H, T);
	printf("[%d] is deleted.\n", delete(H, 3)); print(H, T);


	return 0;
}