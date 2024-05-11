#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define L 1000

typedef char element;
int count = 0;

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

int check(char arr[]) {
	StackType S;
	char c, t;
	int ck = 1, tmp = 0;
	init(&S);

	for (int i = 0; i < strlen(arr); i++) {
		tmp++;
		c = arr[i];
		if (c == '(' || c == '{' || c == '[') {
			push(&S, c);
			count++;
		}
		else if (c == ')' || c == '}' || c == ']') {
			count++;
			if (isEmpty(&S)) {
				ck = 0;
			}
			else {
				t = pop(&S);
				if ((t == '(' && c != ')') || (t == '{' && c != '}') || (t == '[' && c != ']')) {
					ck = 0;
				}
			}
		}
	}
	if (isEmpty(&S))
		return ck;
	else
		return isEmpty(&S);
}

int main() {
	char arr[L];

	scanf("%[^\n]s", arr);

	if (check(arr))
		printf("OK_%d", count);
	else
		printf("Wrong_%d", count);
	
	return 0;
}