#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct Node {
	element key;
	struct Node* next;
}Node;

typedef struct {
	Node* head;
	int size;
}TypeNode;

void init(TypeNode* L) {
	L->head = NULL;
	L->size = 0;
}

void addNode(TypeNode* L, element e) {
	Node* node = (Node*)malloc(sizeof(Node));
	
	node->next = NULL;
	node->key = e;

	if (L->size == 0)
		L->head = node;
	else {
		Node* p = NULL;

		for (p = L->head; p->next != NULL; p = p->next);

		p->next = node;
	}
	L->size += 1;
}

element deleteNode(TypeNode* L) {
	Node* p = L->head;
	element e = p->key;

	L->head = p->next;
	L->size -= 1;
	free(p);

	return e;
}

void partition(TypeNode* L, TypeNode*L1, TypeNode*L2, int k) {
	// L1
	L1->head = L->head;
	L1->size = L->size;
	init(L);

	Node* p = L1->head;

	for (int i = 1; i < k; i++) 
		p = p->next;

	// L2
	L2->head = p->next;
	p->next = NULL;

	L2->size = L1->size - k;
	L1->size = k;
}

TypeNode merge(TypeNode* L1, TypeNode* L2) {
	TypeNode L;
	init(&L);

	while (L1->size != 0 && L2->size != 0) {
		if (L1->head->key < L2->head->key) {
			addNode(&L, L1->head->key);
			deleteNode(L1);
		}
		else {
			addNode(&L, L2->head->key);
			deleteNode(L2);
		}
	}
	if (L1->size == 0) {
		while (L2->size != 0) {
			addNode(&L, L2->head->key);
			deleteNode(L2);
		}
	}
	else {
		while (L1->size != 0) {
			addNode(&L, L1->head->key);
			deleteNode(L1);
		}
	}

	return L;
}

void mergeSort(TypeNode* L) {
	if (L->size > 1) {
		TypeNode L1, L2;
		init(&L1); init(&L2);
		partition(L, &L1, &L2, L->size / 2);
		mergeSort(&L1);
		mergeSort(&L2);
		*L = merge(&L1, &L2);
	}
}

int main() {
	TypeNode L;
	init(&L);
	int n;

	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		element e;
		scanf("%d", &e);
		addNode(&L, e);
	}

	mergeSort(&L);
	
	Node* p = L.head;

	for (int i = 0; i < L.size; i++) {
		printf(" %d", p->key);
		p = p->next;
	}

	return 0;
}