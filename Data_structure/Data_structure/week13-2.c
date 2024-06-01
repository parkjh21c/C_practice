#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct TreeNode {
	element data;
	element id;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

TreeNode* makeNode(element data, element id, TreeNode* left, TreeNode* right) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->data = data;
	node->id = id;
	node->left = left;
	node->right = right;
}

TreeNode* findId(TreeNode *tree ,element id) {
	TreeNode* node = tree;



	return node;
}

// 전위순회
void preOrder(TreeNode* node) {
	if (node != NULL) {
		printf(" %d", node->data);
		preOrder(node->left);
		preOrder(node->right);
	}
}

// 중위순회
void inOrder(TreeNode* node) {
	if (node != NULL) {
		inOrder(node->left);
		printf(" %d", node->data);
		inOrder(node->right);
	}
}

// 후위순회
void postOrder(TreeNode* node) {
	if (node != NULL) {
		postOrder(node->left);
		postOrder(node->right);
		printf(" %d", node->data);
	}
}

int main() {
	TreeNode* F8 = makeNode(80, 8, NULL, NULL);
	TreeNode* F7 = makeNode(130, 7, NULL, NULL);
	TreeNode* F6 = makeNode(120, 6, F7, F8);
	TreeNode* F5 = makeNode(90, 5, NULL, NULL);
	TreeNode* F4 = makeNode(70, 4, NULL, NULL);
	TreeNode* F3 = makeNode(50, 3, NULL, F6);
	TreeNode* F2 = makeNode(30, 2, F4, F5);
	TreeNode* F1 = makeNode(20, 1, F2, F3);
	TreeNode* tree = F1;

	int type, id;

	scanf("%d %d", &type, &id);

	printf("%d", findId(tree, id)->data);
	
}