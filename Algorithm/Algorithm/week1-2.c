#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct TreeNode {
	element id;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

TreeNode* makeNode(element id, TreeNode* left, TreeNode* right) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->id = id;
	node->left = left;
	node->right = right;

	return node;
}

void makeTree(TreeNode* p) {
	if (p != NULL) {
		element id, l, r;
		scanf("%d %d %d", &id, &l, &r);

	}
}

void preOrder(TreeNode* root) {
	if (root != NULL) {
		printf("[%d] ", root->id);
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main() {
	

	return 0;
}