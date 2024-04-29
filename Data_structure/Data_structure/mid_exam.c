#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* next;
}ListNode;

typedef struct ListType {
	ListNode* H;
}ListType;

void init(ListType* L) {
	L->H = (ListNode*)malloc(sizeof(ListNode));
	L->H->next = NULL;
}

void makeSet(ListType* L, element e) {
	ListNode* p = L->H->next, *q = L->H;

	if (p == NULL){
		ListNode* node = (ListNode*)malloc(sizeof(ListNode));
		node->data = e;
		q->next = node;
		node->next = NULL;
	}
	else {
		for (; p != NULL; p = p->next) {
			if (p->data == e)
				return;
			else if (p->data > e) {
				ListNode* node = (ListNode*)malloc(sizeof(ListNode));
				node->data = e;
				node->next = p;
				q->next = node;
				break;
			}
			else
				q = p;
		}
		if (p == NULL) {
			ListNode* node = (ListNode*)malloc(sizeof(ListNode));
			node->data = e;
			node->next = p;
			q->next = node;
		}
	}
}

void Intersect(ListType* L1, ListType* L2, ListType* L3) {
	ListNode* p = L1->H, * q = L2->H;

	for (p = p->next; p != NULL; p = p->next) {
		for (q = L2->H->next; q != NULL; q = q->next) {
			if (p->data == q->data)
				makeSet(L3, p->data);
		}
	}
}

void Union(ListType* L1, ListType* L2, ListType* L3) {
	ListNode* p = L1->H, * q = L2->H->next;
	L3->H->next = p->next;

	for (; q != NULL; q = q->next)
		makeSet(L3, q->data);
}

void Difference(ListType* L1, ListType* L2, ListType* L3) {
	ListNode* p = L1->H, * q = L2->H, * z;

	for (p = L1->H; p != NULL; p = p->next) {
		for (q = L2->H->next; q != NULL; q = q->next) {
			if (p->next->data == q->data) {
				z = p;
				p = p->next;
				z->next = p->next;
				free(p);
				p = z;
			}
		}
	}
	L3->H->next = L1->H->next;

}

void print(ListType* L) {
	ListNode* p = L->H->next;

	printf("{ ");
	for (; p != NULL; p = p->next)
		printf("%d, ", p->data);
	printf("\b\b }\n");
}

int main() {
	ListType L1, L2, L3;
	init(&L1); init(&L2); init(&L3);
	srand(time(NULL));

	for (int i = 0; i < 10; i++) {
		makeSet(&L1, rand() % 30 + 1);
		makeSet(&L2, rand() % 30 + 1); 
	}
	printf("Set 1 = ");
	print(&L1);
	printf("Set 2 = ");
	print(&L2);

	Intersect(&L1, &L2, &L3);
	printf("Inter = ");
	print(&L3);

	init(&L3);
	
	Union(&L1, &L2, &L3);
	printf("Union = ");
	print(&L3);

	init(&L3);
	Difference(&L1, &L2, &L3);
	printf("Diff = ");
	print(&L3);


	return 0;
}