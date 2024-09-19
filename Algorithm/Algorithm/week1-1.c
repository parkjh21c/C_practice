#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct Node {
	element e;
	struct Node* prev;
	struct Node* next;
}Node;

typedef struct {
	Node* H;
	Node* T;
	int length;
}TypeNode;

void init(TypeNode * Tn) {
	Tn->H = (Node*)malloc(sizeof(Node));
	Tn->T = (Node*)malloc(sizeof(Node));
	Tn->H->next = Tn->T;
	Tn->T->prev = Tn->H;
	Tn->H->prev = NULL;
	Tn->T->next = NULL;
	Tn->length = 0;
}

Node* makeNode(element e) {
	Node* node = (Node*)malloc(sizeof(Node));

	node->e = e;
	node->next = NULL;
	node->prev = NULL;

	return node;
}

void addNode(Node* p, element e) {
	Node* node = makeNode(e);
	Node* q = p->next;

	node->next = q;
	q->prev = node;

	node->prev = p;
	p->next = node;
}

void add(TypeNode *Tn, int pos, element e) {
	if (pos <= Tn->length + 1) {
		Node* p = Tn->H;
		Tn->length++;

		for (int i = 1; i < pos; i++)
			p = p->next;

		addNode(p, e);
	}
	else
		printf("invalid position\n");
}

void delete(TypeNode* Tn, int pos) {
	if (Tn->length >= pos) {
		Node* p = Tn->H;

		for (int i = 1; i <= pos; i++) 
			p = p->next;
		Node* q = p->prev;

		q->next = p->next;
		p->next->prev = q;

		free(p);

		Tn->length--;
	}
	else
		printf("invalid position\n");
}

void get_entry(TypeNode* Tn, int pos) {
	if (Tn->length >= pos) {
		Node* p = Tn->H;

		for (int i = 1; i <= pos; i++)
			p = p->next;

		printf("%c\n", p->e);
	}
	else
		printf("invalid position\n");
}

void print(TypeNode* Tn) {
	Node* p = Tn->H->next;

	for (; p != Tn->T; p = p->next)
		printf("%c", p->e);

	printf("\n");
}

int main() {
	TypeNode Tn;
	init(&Tn);

	int N;
	scanf("%d", &N); getchar();
	
	for (int i = 0; i < N; i++) {
		char def;

		scanf("%c", &def);
		
		if (def == 'A') {
			int pos;
			element e;
			scanf("%d %c", &pos, &e); getchar();
			add(&Tn, pos, e);
		}
		else if (def == 'D') {
			int pos;
			scanf("%d", &pos); getchar();
			delete(&Tn, pos);
		}
		else if (def == 'G') {
			int pos;
			scanf("%d", &pos); getchar();
			get_entry(&Tn, pos);
		}
		else if (def == 'P') {
			getchar();
			print(&Tn);
		}
	}

	return 0;
}