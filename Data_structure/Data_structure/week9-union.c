#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int element;

typedef struct DListNode {
	element data;
	struct DListNode* prev;
	struct DListNode* next;
}DListNode;

typedef struct {
	DListNode* H;
	DListNode* T;
	int N;
}SetType;

DListNode* getNode() {
	DListNode* node = (DListNode*)malloc(sizeof(DListNode));
	node->data = 0;
	node->prev = NULL;
	node->next = NULL;
	return node;
}

void init(SetType *S) {
	S->H = getNode();
	S->T = getNode();

	S->H->next = S->T;
	S->T->prev = S->H;
	S->N = 0;
}

void addNode(SetType* S, DListNode* p, element e) {
	DListNode* node = getNode();

	node->data = e;

	node->prev = p;
	node->next = p->next;

	p->next->prev = node;
	p->next = node;

	S->N++;
}

void add(SetType* S, element e) {
	DListNode* p = S->H;
	int status = 1;

	if (p->next == S->T)
		addNode(S, p, e);
	else {
		while (e >= p->next->data && p->next->next != NULL) {
			if (e == p->next->data) {
				status = 0;
				break;
			}
			p = p->next;
		}
		if (status == 1)
			addNode(S, p, e);
	}
}

void traverse(SetType* S) {
	DListNode* p;
	for (p = S->H->next; p != S->T; p = p->next)
		printf("[%d] ", p->data);
	printf("\n");
}

void addLast(SetType* S, element e) {
	DListNode* node = getNode();
	DListNode* p = S->H;

	node->data = e;
	node->next = S->T;
	node->prev = S->T->prev;

	S->T->prev->next = node;
	S->T->prev = node;

	S->N++;
}

void unionSet(SetType* S1, SetType* S2) {
	SetType S3;
	init(&S3);

	DListNode* p = S1->H->next;
	DListNode* q = S2->H->next;

	while (p != S1->T && q != S2->T) {
		if (p->data < q->data) {
			addLast(&S3, p->data);
			p = p->next;
		}
		else if (p->data > q->data) {
			addLast(&S3, q->data);
			q = q->next;
		}
		else {
			addLast(&S3, p->data);
			p = p->next;
			q = q->next;
		}
	}
	while (p != S1->T) {
		addLast(&S3, p->data);
		p = p->next;
	}
	while (q != S2->T) {
		addLast(&S3, q->data);
		q = q->next;
	}

	printf("Union : "); traverse(&S3);
}

int isMember(SetType* S, element e) {
	DListNode* p = S->H->next;
	element a;

	while (1) {
		a = p->data;
		if (a < e) {
			if (p->next == S->T)
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

int isSubset(SetType* S1, SetType* S2) {
	DListNode* p = S1->H->next;

	while (1) {
		if (isMember(S2, p->data)) {
			if (p->next == S1->T)
				return 1;
			else
				p = p->next;
		}
		else
			return 0;
	}
}

int main() {
	SetType A, B;
	init(&A); init(&B);
	srand(time(NULL));

	for (int i = 1; i <= 7; i++) {
		int e1 = rand() % 10 + 1;
		int e2 = rand() % 10 + 1;

		add(&A, e1);
		add(&B, e2);
	}
	
	printf("A : "); traverse(&A);
	printf("B : "); traverse(&B); printf("\n");
	
	unionSet(&A, &B);

	SetType S3, S4;
	init(&S3); init(&S4);

	add(&S3, 3); add(&S3, 7); add(&S3, 8);
	add(&S4, 7); add(&S4, 3); add(&S4, 5); add(&S4, 8);
	
	printf("C : "); traverse(&S3);
	printf("D : "); traverse(&S4); printf("\n");

	if (isSubset(&S3, &S4))
		printf("OK");
	else
		printf("NO");
}