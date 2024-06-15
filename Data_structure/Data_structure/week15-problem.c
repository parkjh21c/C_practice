#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;

typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
}TreeNode;

typedef struct StackType {
	TreeNode** data;
	int top;
}StackType;

void init(StackType* S, int N) {
	S->data = (TreeNode**)malloc(N * sizeof(TreeNode));
	S->top = -1;
}

int isEmpty(StackType* S) {
	return S->top == -1;
}

void push(StackType* S, TreeNode* node) {
	S->top++;
	S->data[S->top] = node;
}

TreeNode* pop(StackType* S) {
	if (isEmpty(S))
		return NULL;

	S->top--;
	return S->data[S->top + 1];
}

TreeNode* makeNode(element key) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->key = key;
	node->left = node->right = NULL;
	return node;
}


// Àç±Í
/*
TreeNode* makeTree(TreeNode * root) {
	int key, left, right;

	scanf("%d %d %d", &key, &left, &right);

	if (root == NULL)
		root = makeNode(key);
	
	if (left != 0) {
		root->left = makeNode(left);
		printf("left : %d\n", root->left->key);
		root->left = makeTree(root->left);
	}

	if (right != 0) {
		root->right = makeNode(right);
		printf("right : %d\n", root->right->key);
		root->right = makeTree(root->right);
	}

	return root;
}
*/

void preOrder(TreeNode* node) {
	if (node != NULL) {
		printf("[%d] ", node->key);
		preOrder(node->left);
		preOrder(node->right);
	}
}

int main() {
	TreeNode* root = NULL, *tmp = NULL;
	StackType S;
	int N;

	scanf("%d", &N);

	init(&S, N);
	root = tmp;

	for (int i = 0; i < N; i++) {
		int key, left, right;

		scanf("%d %d %d", &key, &left, &right);

		if (root == NULL)
			root = tmp = makeNode(key);

		if (tmp == NULL)
			tmp = pop(&S);

		if (left != 0) 
			tmp->left = makeNode(left);

		if (right != 0) {
			tmp->right = makeNode(right);
			push(&S, tmp->right);
		}
		tmp = tmp->left;
	}
	
	int find;

	scanf("%d", &find);

	for (int i = 0; i < find; i++) {
		char ch[101];

		scanf("%s", ch);

		tmp = root;
		printf(" %d", tmp->key);

		for (int j = 0; j < strlen(ch); j++) {
			if (ch[j] == 'R') {
				tmp = tmp->right;
				printf(" %d", tmp->key);
			}
			else {
				tmp = tmp->left;
				printf(" %d", tmp->key);
			}
		}
		printf("\n");
	}

	return 0;
}