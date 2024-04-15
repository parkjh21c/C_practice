#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct CListNode {
	element data;
	struct CListNode* next;
}CListNode;

typedef struct {
	CListNode* T;
	int size;
}CListType;

void init(CListType* CL) {
	CL->T = NULL;
	CL->size = 0;
}

int isEmpty(CListType* CL) {
	return CL->T == NULL;
}

void insertLast(CListType* CL, element e) {
	CListNode* node = (CListNode*)malloc(sizeof(CListNode));
	node->data = e;

	if (isEmpty(CL)) {
		CL->T = node;
		node->next = CL->T;
	}
	else {
		node->next = CL->T->next;
		CL->T->next = node;
		CL->T = node;
	}
	CL->size++;
}

void insertFirst(CListType* CL, element e) {
	CListNode* node = (CListNode*)malloc(sizeof(CListNode));
	node->data = e;

	if (isEmpty(CL)) {
		CL->T = node;
		node->next = CL->T;
	}
	else {
		node->next = CL->T->next;
		CL->T->next = node;
	}
	CL->size++;
}

void print(CListType* CL) {
	if (isEmpty(CL))
		return;
	CListNode* p = CL->T;

	do {
		printf("[%c] => ", p->next->data);
		p = p->next;
	} while (p != CL->T);

	printf("\b\b\b   \n");
}

int main() {
	CListType CL;
	init(&CL);

	insertFirst(&CL, 'D'); print(&CL);

	insertLast(&CL, 'A'); print(&CL);
	insertLast(&CL, 'B'); print(&CL);
	insertLast(&CL, 'C'); print(&CL); getchar();

	insertFirst(&CL, 'E'); print(&CL);
	insertFirst(&CL, 'F'); print(&CL); getchar();

	return 0;
}