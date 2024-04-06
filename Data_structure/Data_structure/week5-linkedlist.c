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

void insertLast(ListType* L, element e) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));	// 새롭게 만들어지는 노드
	node->data = e;
	node->next = NULL;

	if (isEmpty(L))	// if(L->size == 0)
		L->head = node;
	else {
		ListNode* p;
		for (p = L->head; p->next != NULL; p = p->next);

		p->next = node;
	}
	L->size++;
}

void insert(ListType* L, int pos, element e) {
	if (pos == 1)
		insertFirst(L, e);
	else if (pos == L->size + 1)
		insertLast(L, e);
	else {
		ListNode* node = (ListNode*)malloc(sizeof(ListNode));
		ListNode* p = L->head;

		for (int i = 1; i < pos - 1; i++)
			p = p->next;

		node->data = e;
		node->next = p->next;
		p->next = node;

		L->size++;
	}
}

element deleteFirst(ListType* L) {
	if (isEmpty(L)) {
		printf("No Element To Delete.\n");
		return -1;
	}
	ListNode* p = L->head;
	element e = p->data;
	L->head = p->next;
	free(p);
	L->size--;

	return e;
}

element delete(ListType* L, int pos) {
	if (isEmpty(L)) {
		printf("No Element To Delete.\n");
		return -1;
	}

	if (pos < 1 || pos > L->size) {
		printf("Invalid Position.\n");
		return -1;
	}
	else {
		ListNode* p = L->head;
		ListNode* q = NULL;
		element e;

		if (pos == 1)
			e = deleteFirst(L);
		else {
			for (int i = 1; i < pos; i++) {
				q = p;
				p = p->next;
			}
			e = p->data;
			q->next = p->next;
			free(p);
			L->size--;
		}
		return e;
	}
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

	insertLast(&L, 'C'); print(&L);

	insertFirst(&L, 'A'); print(&L);
	insertFirst(&L, 'B'); print(&L);

	insertLast(&L, 'E'); print(&L); getchar();

	insert(&L, 1, 'D'); print(&L);
	insert(&L, 3, 'F'); print(&L);
	insert(&L, 7, 'G'); print(&L); getchar();

	printf("[%c] id deleted.\n", deleteFirst(&L)); print(&L);
	printf("[%c] id deleted.\n", delete(&L, 1)); print(&L);

	return 0;
}