#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
	struct Node* next;
	int data;
}Node;

typedef struct List {
	Node* head;
	Node* tail;
	int count;
}List;

void init(List* L) {
	L->head = NULL;
	L->tail = NULL;
	L->count = 0;
}

void addNode(List* L, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->next = NULL;
	node->data = data;

	if (L->head == NULL) {
		L->head = L->tail = node;
		L->count += 1;
	}
	else {
		Node* p = L->head;
		for (; p != L->tail; p = p->next);

		p->next = node;
		L->tail = node;
		L->count += 1;
	}
}

int findKthSmallest(List *L, int n, int k) {

}

List* buildList(int n, int min, int max) {
	List L;
	init(&L);
	for (int i = 0; i < n; i++) {
		int d = rand() % (max - min + 1) + min;
		addNode(&L, d);
	}

	return &L;
}

int main() {
	List* L;
	srand(time(NULL));
	L = buildList(10, 1, 100);

	// 임시 확인
	Node* p = L->head;
	for (int i = 0; i < 10; i++) {
		printf(" %d", p->data);
		p = p->next;
	}

	return 0;
}