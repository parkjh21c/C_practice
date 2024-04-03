#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct ListNode {
	element data;
	struct ListNode* next;
}ListNode;

typedef struct ListType {
	ListNode* head; // 헤드 포인터 버전
	int size;
}ListType;

void init(ListType* L) {
	L->head = NULL;
	L->size = 0;
}

int isEmpty(ListType* L) {
	// return L->head == NULL;
	return L->size == 0;
}

void insertFirst(ListType* L, element e) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));	// 새롭게 만들어지는 노드
	node->data = e;
	node->next = L->head;
	L->head = node;
	L->size++;
}

void print(ListType* L) {
	ListNode* p;
	for (p = L->head; p != NULL; p = p->next)
		printf("%c => ", p->data);

	printf("\b\b\b   \n");
}

int main() {
	ListType L;
	init(&L);

	insertFirst(&L, 'A'); print(&L);
	insertFirst(&L, 'B'); print(&L);

	return 0;
}