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

int main() {
	TreeNode* root = NULL;
	int n;

	scanf("%d", &n);



	return 0;
}