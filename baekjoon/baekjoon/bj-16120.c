#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;

typedef struct StackNode {
	element data;
	struct StackNode* next;
}StackNode;

typedef struct {
	StackNode* top;
}StackType;

void init(StackType* S) {
	S->top = NULL;
}

int isEmpty(StackType* S) {
	return S->top == NULL;
}

void push(StackType* S, element e) {
	StackNode* node = (StackNode*)malloc(sizeof(StackNode));

	node->data = e;
	node->next = S->top;
	S->top = node;
}

int pop(StackType* S) {
	if (isEmpty(S))
		return 0;

	StackNode* p = S->top;
	S->top = p->next;
	free(p);
	return 1;
}

int check(char ch[]) {
	StackType S;
	init(&S);

	int n = strlen(ch);

	for (int i = 0; i < n; i++) {
		if (ch[i] == 'P')
			push(&S, ch[i]);
		else {
			if (pop(&S) == 0)
				return 0;
			i++;
			if (ch[i] != 'P')
				return 0;
		}
		if (isEmpty(&S))
			return 0;
	}
	pop(&S);
	return isEmpty(&S);
}

int main() {
	char ch[1000001];

	scanf("%s", ch);

	if (check(ch))
		printf("PPAP");
	else
		printf("NP");

	return 0;
}