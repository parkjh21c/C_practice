#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	struct Node* left;
	struct Node* right;
	char data;
}Node;

Node* makeNode(char data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

Node* findNode(Node* node, char data) {
	if (node == NULL) return NULL;
	if (node->data == data)
		return node;
	else if (node->left != NULL && node->left->data == data )
		return node->left;
	else if (node->right != NULL && node->right->data == data)
		return node->right;
	else {
		Node* l = findNode(node->left, data);
		if (l != NULL)
			return l;
		Node* r = findNode(node->right, data);
		if (r != NULL)
			return r;
		return NULL;
	}
}

void addNode(Node** root, char data, char left, char right) {
	if (*root == NULL)
		*root = makeNode(data);

	Node* node = findNode(*root, data);

	if (node == NULL) return;

	if (left != '.')
		node->left = makeNode(left);
	if (right != '.')
		node->right = makeNode(right);
}

void preOrder(Node* root) {
	if (root != NULL) {
		printf("%c", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void midOrder(Node* root) {
	if (root != NULL) {
		midOrder(root->left);
		printf("%c", root->data);
		midOrder(root->right);
	}
}

void lastOrder(Node* root) {
	if (root != NULL) {
		lastOrder(root->left);
		lastOrder(root->right);
		printf("%c", root->data);
	}
}

int main() {
	int N;

	scanf("%d", &N); getchar();

	Node* root = NULL;

	for (int i = 0; i < N; i++) {
		char a, b, c;
		scanf("%c %c %c", &a, &b, &c); getchar();
		addNode(&root, a, b, c);
	}

	preOrder(root);
	printf("\n");
	midOrder(root);
	printf("\n");
	lastOrder(root);
	printf("\n");

	return 0;
}