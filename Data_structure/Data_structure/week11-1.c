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
    if (isEmpty(S)) {
        printf("Stack Empty\n");
        return -1;
    }

    StackNode* p = S->top;
    element e = p->data;
    S->top = S->top->next;
    free(p);

    if (e == '_')
        e = '-';
    else if (e == '=')
        e = '+';

    return e;
}

element peek(StackType* S) {
    if (isEmpty(S)) {
        printf("Stack Empty\n");
        return -1;
    }

    return S->top->data;
}

int prec(char op) {
    switch (op) {
        case '(': case ')':
            return 0;
        case '|':
            return 1;
        case '&':
            return 2;
        case '<': case '>':
            return 3;
        case '-': case '+':
            return 4;
        case '/': case '*':
            return 5;
        case '!': case '_': case '=':   // _ -> -, = -> +
            return 6;
        default:
            return -1;
    }
}


// status 로 조절 해보기
void convert(char ch[]) {
    StackType S;
    init(&S);

    char c, t;
    int n = strlen(ch), i = 0;
    int status = 0;

    if (ch[i] == '+') {
        ch[i] = '=';
        push(&S, ch[i]);
        i++;
    }
    else if (ch[i] == '-') {
        ch[i] = '_';
        push(&S, ch[i]);
        i++;
    }

    for (; i < n; i++) {
        c = ch[i];
        
        switch (c) {
            case '+': case '-': case '*': case '/':
                if (status == 1) {
                    if (c == '+')
                        c = '=';
                    else
                        c = '_';
                }
                    
                while (!isEmpty(&S) && (prec(c) <= prec(peek(&S))))
                    printf("%c", pop(&S));

                push(&S, c);
                status = 1;
                break;

            case '(':
                push(&S, c);
                status = 1;
                break;

            case ')':
                t = pop(&S);
                while (t != '(') {
                    printf("%c", t);
                    t = pop(&S);
                }
                break;

            case '&': case '|':
                i++;
                while (!isEmpty(&S) && (prec(c) <= prec(peek(&S))))
                    printf("%c", pop(&S));

                push(&S, c);
                push(&S, c);
                status = 1;
                break;

            case '<': case '>':
                while (!isEmpty(&S) && (prec(c) <= prec(peek(&S))))
                    printf("%c", pop(&S));

                push(&S, c);
                status = 1;
                break;

            case '!':
                push(&S, c);
                break;

            default:
                printf("%c", c);
                status = 0;
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
        convert(ch);
    }
    return 0;
}