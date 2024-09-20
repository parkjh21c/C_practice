#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
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

void searching(TreeNode* root, char ch[]) {
	TreeNode* p = root;
	element s[100];
	int len = 0;
	
	s[len] = p->id;
	len++;

	for (int i = 0; i < strlen(ch); i++) {
		if (ch[i] == 'L') {
			p = p->left;
			if (p == NULL) {
				len = -1;
				break;
			}
			s[len] = p->id;
			len++;
		}
		else if (ch[i] == 'R'){
			p = p->right;
			if (p == NULL) {
				len = -1;
				break;
			}
			s[len] = p->id;
			len++;
		}
	}

	if (len >= 0) {
		for (int i = 0; i < len; i++)
			printf(" %d", s[i]);
		printf("\n");
	}
}

int main() {
	int n;
	TreeNode* root = makeNode(0, NULL, NULL);

	scanf("%d", &n);
	makeTree(root);
	
	int m;
	char ch[101];
	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		scanf("%s", ch);
		searching(root, ch);
	}
	

	return 0;
}