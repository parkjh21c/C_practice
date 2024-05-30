#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct TreeNode {
	element data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

TreeNode* makeNode(element data, TreeNode* left, TreeNode* right) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	
	node->data = data;
	node->left = left;
	node->right = right;

	return node;
}

void print(TreeNode* F) {
	printf("%d", F->data);

	if (F->left != NULL)
		printf(" %d", F->left->data);
	if (F->right != NULL)
		printf(" %d", F->right->data);
}

int main() {
	TreeNode* F8 = makeNode(80, NULL, NULL);
	TreeNode* F7 = makeNode(130, NULL, NULL);
	TreeNode* F6 = makeNode(120, F7, F8);
	TreeNode* F5 = makeNode(90, NULL, NULL);
	TreeNode* F4 = makeNode(70, NULL, NULL);
	TreeNode* F3 = makeNode(50, NULL, F6);
	TreeNode* F2 = makeNode(30, F4, F5);
	TreeNode* F1 = makeNode(20, F2, F3);

	int num;

	scanf("%d", &num);

	switch (num) {
	case(1):
		print(F1);
		break;
	case(2):
		print(F2);
		break;
	case(3):
		print(F3);
		break;
	case(4):
		print(F4);
		break;
	case(5):
		print(F5);
		break;
	case(6):
		print(F6);
		break;
	case(7):
		print(F7);
		break;
	case(8):
		print(F8);
		break;
	default:
		printf("-1");
		break;
	}

	return 0;
}