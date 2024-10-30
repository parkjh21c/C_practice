#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct TreeNode {
	struct TreeNode* lChild;
	struct TreeNode* rChild;
	struct TreeNode* parent;
	element key;
	int height;
}TreeNode;

TreeNode* makeNode(TreeNode* parent, element key, int height) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));

	node->parent = parent;
	node->key = key;
	node->height = height;
	node->lChild = NULL;
	node->rChild = NULL;

	return node;
}

TreeNode* insertNode(TreeNode* root, element key) {
	if (root == NULL)
		return makeNode(NULL, key);

	else {
		TreeNode* p = root, * q = NULL;
		while (p != NULL) {
			q = p;
			if (p->key > key)
				p = p->lChild;

			else
				p = p->rChild;
		}
		p = makeNode(q, key);
		if (q->key > key)
			q->lChild = p;
		else
			q->rChild = p;
	}
	return root;
}

// 재귀
/*
TreeNode* insertNode2(TreeNode* root, element key) {
	if (root == NULL)
		return makeNode(NULL, key);

	if (root->key > key) {
		root->lChild = insertNode2(root->lChild, key);
		root->lChild->parent = root;
	}
	else {
		root->rChild = insertNode2(root->rChild, key);
		root->rChild->parent = root;
	}
	return root;
}
*/

void findKey(TreeNode* root, element key) {
	TreeNode* p = root;
	while (p != NULL) {
		if (p->key > key)
			p = p->lChild;
		else if (p->key < key)
			p = p->rChild;
		else {
			printf("%d\n", key);
			return;
		}
	}
	printf("X\n");
}

TreeNode* findNode(TreeNode* root, element key) {
	if (root == NULL) return NULL;

	if (root->key == key)
		return root;
	else if (root->key < key)
		return findNode(root->rChild, key);
	else
		return findNode(root->lChild, key);
}

int checkLeaf(TreeNode* node) {
	// 자식이 없는 경우 0
	if (node->lChild == NULL && node->rChild == NULL)
		return 0;

	// 자식이 왼쪽만 없는 경우 1
	else if (node->lChild == NULL)
		return 1;

	// 자식이 오른쪽만 없는 경우 2
	else if (node->rChild == NULL)
		return 2;
	// 자식이 모두 있는 경우
	else
		return 3;
}


int removeNode(TreeNode** root, element key) {
	TreeNode* node = findNode(*root, key);


	if (node == NULL) {
		printf("X\n");
		return -1;
	}

	TreeNode* p = node->parent;
	element delkey = node->key;

	// 자식 노드가 없는 노드
	if (checkLeaf(node) == 0) {
		if (p == NULL)
			*root = NULL;
		else {
			if (p->lChild == node)
				p->lChild = NULL;
			else
				p->rChild = NULL;
		}
		free(node);
	}

	else if (checkLeaf(node) == 1) {	// null left
		if (p == NULL) {
			*root = node->rChild;
			(*root)->parent = NULL;
		}
		else {
			if (p->lChild == node) {
				p->lChild = node->rChild;
				node->rChild->parent = p;
			}
			else {
				p->rChild = node->rChild;
				node->rChild->parent = p;
			}
		}
		free(node);

	}
	else if (checkLeaf(node) == 2) {	// null right
		if (p == NULL) {
			*root = node->lChild;
			(*root)->parent = NULL;
		}
		else {
			if (p->lChild == node) {
				p->lChild = node->lChild;
				node->lChild->parent = p;
			}
			else {
				p->rChild = node->lChild;
				node->lChild->parent = p;
			}
		}
		free(node);
	}

	else if (checkLeaf(node->lChild) == 0 && checkLeaf(node->rChild) == 0) {
		if (p == NULL) {
			*root = node->lChild;
			(*root)->parent = NULL;
			(*root)->rChild = node->rChild;
		}
		else {
			if (p->lChild == node) {
				p->lChild = node->lChild;
				p->lChild->parent = p;
				p->lChild->rChild = node->rChild;
				p->lChild->rChild->parent = p->lChild;
			}
			else {
				p->rChild = node->lChild;
				p->rChild->parent = p;
				p->rChild->rChild = node->rChild;
				p->rChild->rChild->parent = p->rChild;
			}
		}

		free(node);
	}

	// 양쪽 다 내부 노드인 경우
	else {
		TreeNode* q = node->rChild;
		while (q->lChild != NULL)
			q = q->lChild;

		element tmp = q->key;	// 임시 저장

		removeNode(root, tmp);
		node->key = tmp;
	}
	return delkey;
}

void preorderTree(TreeNode* node) {
	if (node != NULL) {
		printf(" %d", node->key);
		preorderTree(node->lChild);
		preorderTree(node->rChild);
	}
}

int main() {
	TreeNode* root = NULL;

	while (1) {
		char o;
		element k;
		scanf("%c", &o);

		if (o == 'i') {
			scanf("%d", &k); getchar();
			root = insertNode(root, k);
		}
		else if (o == 'd') {
			scanf("%d", &k); getchar();
			element del_s = removeNode(&root, k);
			if (del_s != -1)
				printf("%d\n", del_s);
		}
		else if (o == 's') {
			scanf("%d", &k); getchar();
			findKey(root, k);
		}
		else if (o == 'p') {
			preorderTree(root);
			printf("\n");
		}
		else if (o == 'q')
			break;
	}

	return 0;
}