#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef char element;
int count;

typedef struct DListNode {
	element data;
	struct DListNode* prev;
	struct DListNode* next;
}DListNode;

void init(DListNode* H, DListNode *T) {
	H->next = T;
	T->prev = H;
	count = 0;
}

void AddNode(DListNode* H, int pos, element e) {
	DListNode* p = H;

	if (count + 1 < pos)
		printf("invalid position\n");
	else {
		for (int i = 1; i < pos; i++)
			p = p->next;
		
		DListNode* node = (DListNode*)malloc(sizeof(DListNode));
		
		node->data = e;
		node->prev = p;
		node->next = p->next;
		
		p->next->prev = node;
		p->next = node;
		
		count++;
	}
}

void DeleteNode(DListNode* H, int pos) {
	DListNode* p = H;

	if (count < pos)
		printf("invalid position\n");
	else {
		for (int i = 1; i <= pos; i++) 
			p = p->next;
		
		p->next->prev = p->prev;
		p->prev->next = p->next;
		free(p);

		count--;
	}
}

element GetNode(DListNode* H, int pos) {
	DListNode* p = H;
	element e;

	if (count < pos) {
		printf("invalid position\n");
		e = '_';
		return e;
	}
	else {
		for (int i = 1; i <= pos; i++)
			p = p->next;

		e = p->data;

		return e;
	}
}

void print(DListNode* H) {
	DListNode* p = H->next;
	for (int i = 0; i < count; i++) {
		printf("%c", p->data);
		p = p->next;
	}
	printf("\n");
}

int main() {
	DListNode* H = (DListNode*)malloc(sizeof(DListNode));
	DListNode* T = (DListNode*)malloc(sizeof(DListNode));
	element ch;
	int N, pos;
	char F;

	init(H, T);

	scanf("%d", &N); getchar();

	for (int i = 0; i < N; i++) {
		scanf("%c", &F);

		if (F == 'A') {
			scanf("%d %c", &pos, &ch); getchar();
			AddNode(H, pos, ch);
		}
		else if (F == 'D') {
			scanf("%d", &pos); getchar();
			DeleteNode(H, pos);
			if (count == 0)
				init(H, T);
		}
		else if (F == 'G') {
			scanf("%d", &pos); getchar();
			ch = GetNode(H, pos);
			if (ch != '_')
				printf("%c\n", ch);
		}
		else if (F == 'P') {
			getchar();
			print(H);
		}
	}
	return 0;
}