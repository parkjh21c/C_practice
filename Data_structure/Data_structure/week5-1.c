#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int coef;	// ���� ���
	int exp;	// ���� ����
	struct ListNode* next;
}ListNode;

typedef struct ListType {
	ListNode* head;
	int size;
}ListType;

void init(ListType* L) {
	L->head = NULL;
	L->size = 0;
}

int isEmpty(ListType* L) {
	return L->size == 0;
}

void appendTerm(ListType* L, int coef, int exp) {
	ListNode* node;

	node = (ListNode*)malloc(sizeof(ListNode));

	node->next = NULL;
	node->coef = coef;
	node->exp = exp;

	if (isEmpty(L)) 	// ù��° ����� ��
		L->head = node;

	else {
		ListNode* p;
		for (p = L->head; p->next != NULL; p = p->next);

		p->next = node;
	}
	L->size++;
}

void print(ListType* L) {
	ListNode* p;

	for (p = L->head; p != NULL; p = p->next)
		printf(" %d %d",p->coef, p->exp);
}

void addPoly(ListType* a, ListType* b) {
	ListType result;
	ListNode* i, * j;
	init(&result);
	
	i = a->head;
	j = b->head;

	while ((i != NULL) && (j != NULL)) {
		if (i->exp > j->exp) {
			appendTerm(&result, i->coef, i->exp);
			i = i->next;
		}
		else if (i->exp < j->exp) {
			appendTerm(&result, j->coef, j->exp);
			j = j->next;
		}
		else {
			int sum = i->coef + j->coef;
			
			if (sum != 0)
				appendTerm(&result, sum, i->exp);
			i = i->next;
			j = j->next;
		}
	}
	while (i != NULL) {
		appendTerm(&result, i->coef, i->exp);
		i = i->next;
	}
	while (j != NULL) {
		appendTerm(&result, j->coef, j->exp);
		j = j->next;
	}
	print(&result);
}

int main() {
	ListType a, b;
	int N; // ���� ����
	int c, e;	// ���� ���, ����
	
	init(&a); init(&b);

	// ù ��° ���׽�
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &c, &e);
		appendTerm(&a, c, e);
	}

	// �� ��° ���׽�
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &c, &e);
		appendTerm(&b, c, e);
	}

	addPoly(&a, &b);

	return 0;
}