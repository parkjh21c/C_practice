#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* next;
}ListNode;

typedef struct ListType {
	ListNode* H;
	int N;
}ListType;

ListNode* getNode() {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = 0;
	node->next = NULL;

	return node;
}

void init(ListType* L) {
	L->H = getNode();
	L->N = 0;
}

void addNode(ListType* L, ListNode* p, element e) {
	ListNode* node = getNode();
	
	node->data = e;
	node->next = p->next;
	p->next = node;

	L->N++;
}

void add(ListType* L, element e) {
	ListNode* p = L->H;
	int status = 1;

	if (L->H->next == NULL) 
		addNode(L, p, e);
	else {
		while (p->next != NULL && p->next->data <= e) {
			if (p->next->data == e) {
				status = 0;
				break;
			}
			p = p->next;
		}
		if (status == 1) 
			addNode(L, p, e);
	}
}

ListNode* Union(ListType* L1, ListType* L2) {
	ListType L3;
	init(&L3);

	for (ListNode* p = L1->H->next; p != NULL; p = p->next)
		add(&L3, p->data);
	
	for (ListNode* p = L2->H->next; p != NULL; p = p->next)
		add(&L3, p->data);

	return L3.H;
}

ListNode* intersect(ListType* L1, ListType* L2) {
	ListNode* p = L1->H->next, * q = L2->H->next;
	ListType L3;
	init(&L3);

	while (p != NULL && q != NULL){
		if (p->data > q->data)
			q = q->next;
		else if (p->data < q->data)
			p = p->next;
		else {
			add(&L3, p->data);
			p = p->next;
			q = q->next;
		}
	}

	return L3.H;
}

void print(ListNode* L) {
	ListNode *p = L->next;

	if (p != NULL) {
		for (; p!= NULL; p = p->next) 
			printf(" %d", p->data);
	}
	else
		printf(" 0");
	printf("\n");
}

int main() {
	ListType A, B;
	init(&A); init(&B);

	int size_A, size_B;
	element e;

	scanf("%d", &size_A);

	for (int i = 0; i < size_A; i++) {
		scanf("%d", &e);
		add(&A, e);
	}

	scanf("%d", &size_B);

	for (int i = 0; i < size_B; i++) {
		scanf("%d", &e);
		add(&B, e);
	}

	print(Union(&A, &B));
	print(intersect(&A, &B));

	return 0;
}