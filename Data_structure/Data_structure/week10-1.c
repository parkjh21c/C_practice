#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;
int N;

typedef struct {
	element stack[100];
	int top;
}StackType;

void init(StackType* S) {
	for (int i = 0; i < N; i++)
		S->stack[i] = '-';
	S->top = -1;
}

int isEmpty(StackType* S) {
	return S->top == -1;
}

int isFull(StackType* S) {
	return S->stack[N - 1] != '-';
}

void push(StackType* S, element e) {
	if (isFull(S)) 
		printf("Stack FULL\n");
	else {
		S->top++;
		S->stack[S->top] = e;
	}
}

element pop(StackType* S) {
	if (isEmpty(S)) {
		printf("Stack Empty\n");
		return -1;
	}
	else {
		element e = S->stack[S->top];
		S->stack[S->top] = '-';
		S->top--;
		return e;
	}
}

void peek(StackType* S) {
	if (isEmpty(S)) 
		printf("Stack Empty\n");
	else 
		printf("%c\n", S->stack[S->top]);
}

void duplicate(StackType* S) {
	if (isEmpty(S))
		printf("Stack FULL\n");
	else {
		element e = pop(S);
		push(S, e);
		push(S, e);
	}
}

void upRotate(StackType* S, int n) {
	if (n <= S->top + 1) {
		char tmp = S->stack[S->top];
		int i;

		for (i = S->top; i > S->top - n + 1; i--)
			S->stack[i] = S->stack[i - 1];
		S->stack[i] = tmp;
	}
}

void downRotate(StackType* S, int n) {
	if (n <= S->top + 1) {
		char tmp = S->stack[S->top - n + 1];
		int i;

		for (i = S->top - n + 1; i < S->top; i++)
			S->stack[i] = S->stack[i + 1];
		S->stack[i] = tmp;
	}
}

void print(StackType* S) {
	for (int i = S->top; i >= 0; i--)
		printf("%c", S->stack[i]);
	printf("\n");
}

int main() {
	StackType S;
	int count;

	scanf("%d", &N);
	init(&S);

	scanf("%d", &count);

	for (int i = 0; i < count; i++) {
		char str[10];
		scanf("%s", str); getchar();

		if (strcmp(str, "PUSH") == 0) {
			element e;
			scanf("%c", &e);
			push(&S, e);
		}
		else if (strcmp(str, "POP") == 0)
			pop(&S);
		else if (strcmp(str, "PEEK") == 0)
			peek(&S);
		else if (strcmp(str, "DUP") == 0)
			duplicate(&S);
		else if (strcmp(str, "UpR") == 0) {
			int t;
			scanf("%d", &t);
			upRotate(&S, t);
		}
		else if (strcmp(str, "DownR") == 0) {
			int t;
			scanf("%d", &t);
			downRotate(&S, t);
		}
		else if (strcmp(str, "PRINT") == 0)
			print(&S);
	}


	return 0;
}