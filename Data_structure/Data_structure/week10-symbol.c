#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define N 100

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

element pop(StackType* S) {
	if (isEmpty(S)) {
		printf("Stack is Empty.\n");
		return -1;
	}

	StackNode* p = S->top;
	element e = p->data;
	S->top = p->next;
	free(p);

	return e;
}

element peek(StackType* S) {
	if (isEmpty(S)) {
		printf("Stack is Empty.\n");
		return -1;
	}

	return S->top->data;
}

void print(StackType* S) {
	StackNode* p;
	for (p = S->top; p != NULL; p = p->next)
		printf("[%c] -> ", p->data);
	printf("NULL.");
}

int check(char str[]) {
	StackType S;
	init(&S);

	char c, t;
	int n = strlen(str);

	for (int i = 0; i < n; i++) {
		c = str[i];

		if (c == '(' || c == '{' || c == '[')
			push(&S, c);
		else if (c == ')' || c == '}' || c == ']') {
			if (isEmpty(&S))
				return 0;
			else {
				t = pop(&S);
				if ((t == '(' && c != ')') || (t == '{' && c != '}') || (t == '[' && c != ']'))
					return 0;
			}
		}
	}
	return isEmpty(&S);
}

int main() {
	char str[N];
	scanf("%s", str);

	if (check(str))
		printf("OK!!!\n");
	else
		printf("NO!!!\n");

	return 0;
}