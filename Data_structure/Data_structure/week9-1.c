#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* next;
}ListNode;

typedef struct ListType {
	ListNode* head;
	int N;
}ListType;

ListNode* getNode() {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = 0;
	node->next = NULL;
	return node;
}

void init(ListType* L) {
	L->head = NULL;
	L->N = 0;
}

void addFirst(ListType* L, element e) {
	ListNode* node = getNode();

	node->data = e;
	node->next = L->head;
	L->head = node;

	L->N++;
}

void addNode(ListType* L, ListNode* p, element e) {
	ListNode* node = getNode();

	node->data = e;
	node->next = p->next;
	p->next = node;

	L->N;
}

void add(ListType* L, element e) {
	if (L->head == NULL)
		addFirst(L, e);
	else if (L->head->data >= e) {
		if (L->head->data != e)
			addFirst(L, e);
	}
	else {
		ListNode* p = L->head;
		int status = 1;
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

int isMember(ListType* L, element e) {
	if (L->head == NULL)
		return 0;
	else {
		ListNode* p = L->head;
		int a;
		while (1) {
			a = p->data;
			if (a < e) {
				if (p->next == NULL)
					return 0;
				else
					p = p->next;
			}
			else if (a > e)
				return 0;
			else
				return 1;
		}
	}
}

int isSubset(ListType* A, ListType* B) {
	if (A->head == NULL)
		return 0;
	else {
		ListNode* p = A->head;
		while (1) {
			if (isMember(B, p->data)) {
				if (p->next == NULL)
					return 0;
				else
					p = p->next;
			}
			else
				return p->data;
		}
	}
}

void print(ListType* L) {

	if (L->head != NULL) {
		ListNode* p = L->head;
		for (; p != NULL; p = p->next)
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

	printf("%d", isSubset(&A, &B));

	return 0;
}