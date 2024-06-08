#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

#define N 8

typedef int element;

typedef struct TreeNode {
	element data;
	element id;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

typedef struct {
	TreeNode* data[N];
	int front, rear;
}QueueType;

void init(QueueType* Q) {
	Q->front = Q->rear = 0;
}

int isEmpty(QueueType* Q) {
	return Q->front == Q->rear;
}

int isFull(QueueType* Q) {
	return Q->front == (Q->rear + 1) % N;
}

void enqueue(QueueType* Q, TreeNode* e) {
	if (isFull(Q))
		printf("FULL\n");
	else {
		Q->rear = (Q->rear + 1) % N;
		Q->data[Q->rear] = e;
	}
}

TreeNode* dequeue(QueueType* Q) {
	if (isEmpty(Q))
		return NULL;

	Q->front = (Q->front + 1) % N;
	return Q->data[Q->front];
}


TreeNode* makeNode(element data, element id, TreeNode* left, TreeNode* right) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->data = data;
	node->id = id;
	node->left = left;
	node->right = right;

	return node;
}

TreeNode* findId(TreeNode* tree, element id) {
	TreeNode* node = tree;
	QueueType Q;
	init(&Q);

	enqueue(&Q, tree);

	while (!isEmpty(&Q)) {
		node = dequeue(&Q);

		if (node->id == id)
			return node;

		if (node->left)
			enqueue(&Q, node->left);

		if (node->right)
			enqueue(&Q, node->right);
	}

	return NULL;
}

// 전위순회
void sumpreOrder(TreeNode* node, int *total) {
	if (node != NULL) {
		*total += node->data;
		sumpreOrder(node->left, total);
		sumpreOrder(node->right, total);
	}
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

	int total = 0, id;

	scanf("%d", &id);
	tree = findId(F1, id);
	if (tree == NULL)
		printf("-1");

	sumpreOrder(tree, &total);
	printf("%d", total);

	return 0;
}