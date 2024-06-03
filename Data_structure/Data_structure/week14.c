#include <stdio.h>
#include <stdlib.h>

// 스택으로 inorder 만들기
// 시험 비슷하게 출제 예정

#define N 13

typedef char element;

typedef struct TreeNode {
	element key;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

TreeNode* makeNode(element key, TreeNode* left, TreeNode* right) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->key = key;
	node->left = left;
	node->right = right;

	return node;
}

typedef struct {
	TreeNode *data[N];
	int top;
}StackType;

void init(StackType* S) {
	S->top = -1;
}

int isEmpty(StackType* S) {
	return S->top == -1;
}

int isFull(StackType* S) {
	return S->top == N - 1;
}

void push(StackType* S, TreeNode* e) {
	if (!isFull(S))
		S->data[++S->top] = e;
}

TreeNode* pop(StackType* S) {
	TreeNode* e = NULL;

	if (!isEmpty(S))
		e = S->data[S->top--];

	return e;
}

void iterInOrder(TreeNode* root) {
	StackType S;
	init(&S);

	while (1) {
		for (; root != NULL; root = root->left)
			push(&S, root);

		root = pop(&S);

		if (root == NULL)
			break;

		printf("[%c] ", root->key);
		root = root->right;		
	}
}

void inOrder(TreeNode* node) {
	if (node != NULL) {
		inOrder(node->left);
		printf("[%c] ", node->key);
		inOrder(node->right);
	}
}

void postOrder(TreeNode* node) {
	if (node != NULL) {
		postOrder(node->left);
		postOrder(node->right);
		printf("[%c] ", node->key);
	}
}

void preOrder(TreeNode* node) {
	if (node != NULL) {
		printf("[%c] ", node->key);
		preOrder(node->left);
		preOrder(node->right);
	}
}

int main() {
	TreeNode* n11 = makeNode('I', NULL, NULL);
	TreeNode* n10 = makeNode('H', NULL, NULL);
	TreeNode* n7 = makeNode('G', NULL, NULL);
	TreeNode* n6 = makeNode('F', NULL, NULL);
	TreeNode* n5 = makeNode('E', n10, n11);
	TreeNode* n4 = makeNode('D', NULL, NULL);
	TreeNode* n3 = makeNode('C', n6, n7);
	TreeNode* n2 = makeNode('B', n4, n5);
	TreeNode* n1 = makeNode('A', n2, n3);

	printf("Pre : "); preOrder(n1); printf("\n");
	printf("In : "); inOrder(n1); printf("\n");
	printf("Post : "); postOrder(n1); printf("\n");

	printf("inter : "); iterInOrder(n1); printf("\n");

	return 0;
}