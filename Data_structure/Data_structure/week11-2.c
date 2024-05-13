#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;

typedef struct StackNode {
    element data;
    struct StackNode* next;
}StackNode;

typedef struct StackType {
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
    if (isEmpty(S))
    {
        printf("Stack Empty\n");
        return -1;
    }

    StackNode* p = S->top;
    element e = p->data;
    S->top = S->top->next;
    free(p);

    return e;
}

element peek(StackType* S) {
    if (isEmpty(S))
    {
        printf("Stack Empty\n");
        return -1;
    }

    return S->top->data;
}

int evaluate(char* postfix) {
    StackType S;
    init(&S);

    int op1, op2, digit;
    char c;

    int n = strlen(postfix);

    for (int i = 0; i < n; i++) {
        c = postfix[i];
        if (c != '+' && c != '-' && c != '*' && c != '/') {
            digit = c - '0';
            push(&S, digit);
        }
        else {
            op2 = pop(&S);
            op1 = pop(&S);

            switch (c) {
            case '+':
                push(&S, op1 + op2);
                break;
            case '-':
                push(&S, op1 - op2);
                break;
            case '*':
                push(&S, op1 * op2);
                break;
            case '/':
                push(&S, op1 / op2);
                break;
            }
        }
    }
    return pop(&S);
}

int prec(char op) {
    switch (op) {
    case '(': case ')':
        return 0;
    case '+': case '-':
        return 1;
    case '*': case '/':
        return 2;
    }
}

void convert(char* infix) {
    StackType S;
    init(&S);

    char c, t;
    int n = strlen(infix);

    for (int i = 0; i < n; i++) {
        c = infix[i];
        switch (c) {
        case '+': case '-': case '*': case '/':
            while (!isEmpty(&S) && (prec(c) <= prec(peek(&S))))
                printf("%c", pop(&S));

            push(&S, c);
            break;

        case '(':
            push(&S, c);
            break;

        case ')':
            t = pop(&S);
            while (t != '(') {
                printf("%c", t);
                t = pop(&S);
            }
            break;

        default:
            printf("%c", c);
            break;
        }
    }
    while (!isEmpty(&S))
        printf("%c", pop(&S));
    printf("\n");
}

int main() {
    int N;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        char ch[101];
        scanf("%s", ch);
        printf("%d\n",evaluate(ch));
    }

    return 0;
}
