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

void makeTree(TreeNode *p) {
	if (p != NULL) {
		element id, left, right;
		scanf("%d %d %d", &id, &left, &right);
		p->id = id;

		if (left != 0) {
			p->left = makeNode(left, NULL, NULL);
			makeTree(p->left);
		}
		if (right != 0) {
			p->right = makeNode(right, NULL, NULL);
			makeTree(p->right);
		}
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
	int n;
	TreeNode* root = makeNode(0, NULL, NULL);

	scanf("%d", &n);
	makeTree(root);
	
	return 0;
}