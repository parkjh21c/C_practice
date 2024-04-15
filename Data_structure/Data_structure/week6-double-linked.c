#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct DListNode {
	element data;
	struct DListNode* prev;
	struct DListNode* next;
}DListNode;

typedef struct {
	DListNode* H;	// ù��° ���
	DListNode* T;	// ������ ���
	int count;
}DListType;

void init(DListType* DL) {
	DL->H = NULL;
	DL->T = NULL;
	DL->count = 0;
}

int isEmpty(DListType* DL) {
	return DL->H == NULL;
}

void insertFirst(DListType* DL, element e) {
	DListNode* node = (DListNode*)malloc(sizeof(DListNode));
	DListNode* p = DL->H;

	node->data = e;
	node->prev = NULL;
	node->next = p;

	if (p == NULL)
		DL->H = DL->T = node;
	else {
		p->prev = node;
		DL->H = node;
	}
	DL->count++;
}

void insertLast(DListType* DL, element e) {
	DListNode* node = (DListNode*)malloc(sizeof(DListNode));
	DListNode* p = DL->T;

	node->data = e;
	node->prev = p;
	node->next = NULL;

	if (p == NULL)
		DL->H = DL->T = node;
	else {
		p->next = node;
		DL->T = node;
	}
	DL->count++;
}

void insert(DListType* DL, int pos, element e) {
	DListNode* node = (DListNode*)malloc(sizeof(DListNode));
	DListNode* p = DL->H;

	if (pos == 1)
		insertFirst(DL, e);
	else if (pos == DL->count + 1)
		insertLast(DL, e);
	else {
		for (int i = 1; i < pos; i++)
			p = p->next;

		node->data = e;
		node->prev = p->prev;
		node->next = p;

		p->prev->next = node;
		p->prev = node;

		DL->count++;
	}

}

// delete�Լ��� ����� �� ��
// ���� �� ��尡 ���ٸ� => init �Լ� ȣ�� �ʿ�
element deleteFirst(DListType* DL) {
	if (isEmpty(DL)) {
		printf("No Element To Delete.\n");
		return -1;
	}
	
	DListNode* p = DL->H;
	element e = p->data;

	if (p->next != NULL) {
		DL->H = p->next;
		p->next->prev = NULL;

	}
	else {
		init(DL);
		return e;
	}
	free(p);

	DL->count--;

	return e;
}

element deleteLast(DListType* DL) {
	if (isEmpty(DL)) {
		printf("No Element To Delete.\n");
		return -1;
	}

	DListNode* p = DL->T;
	element e = p->data;

	if (p->prev != NULL) {
		DL->T = p->prev;
		p->prev->next = NULL;
	}
	else {
		init(DL);
		return e;
	}
	free(p);

	DL->count--;

	return e;
}

element delete(DListType* DL, int pos) {
	if (isEmpty(DL)) {
		printf("No Element To Delete.\n");
		return -1;
	}
	else if (pos < 1 || pos > DL->count) {
		printf("Invalid Position.\n");
		return -1;
	}
	else {
		DListNode* p = DL->H;
		element e;

		if (pos == 1)
			e = deleteFirst(DL);
		// else if (DL->count == pos)
		//	e = deleteLast(DL);
		else {
			for (int i = 1; i < pos; i++)
				p = p->next;

			if (p->next != NULL) {
				p->next->prev = p->prev;
				p->prev->next = p->next;
			}
			else {
				p->prev->next = NULL;
				DL->T = p->prev;
			}
			e = p->data;
			free(p);

			DL->count--;
		}
		return e;
	}
}

void print(DListType* DL) {
	for (DListNode* p = DL->H; p != NULL; p = p->next)
		printf("[%d] <=> ", p->data);
	printf("\b\b\b\b   \n");
}

int main() {
	DListType DL;
	init(&DL);

	insertFirst(&DL, 20); print(&DL);
	printf("[%d] is deleted\n", deleteFirst(&DL)); print(&DL);
	insertLast(&DL, 99); print(&DL);
	insertFirst(&DL, 10); print(&DL);
	insertFirst(&DL, 30); print(&DL); getchar();

	insertLast(&DL, 50); print(&DL);
	insertLast(&DL, 80); print(&DL);
	insertLast(&DL, 90); print(&DL); getchar();

	insert(&DL, 1, 70); print(&DL);
	insert(&DL, DL.count + 1, 100); print(&DL);
	insert(&DL, 3, 110); print(&DL); getchar();

	printf("[%d] is deleted.\n", deleteFirst(&DL)); print(&DL);
	printf("[%d] is deleted.\n", deleteFirst(&DL)); print(&DL);

	printf("[%d] is deleted.\n",deleteLast(&DL)); print(&DL);
	printf("[%d] is deleted.\n", deleteLast(&DL)); print(&DL); getchar();

	printf("[%d] is deleted.\n", delete(&DL, 3)); print(&DL);
	printf("[%d] is deleted.\n", delete(&DL, 4)); print(&DL);
	printf("[%d] is deleted.\n", deleteLast(&DL)); print(&DL);

	return 0;
}