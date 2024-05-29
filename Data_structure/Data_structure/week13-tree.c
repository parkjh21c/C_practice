#include <stdio.h>
#include <stdlib.h>

#define N 13

typedef char element;

typedef struct TreeNode {
	element key;
	struct TreeNode* parent;	// Optional
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
	return Q->rear == Q->front;
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

TreeNode* makeNode(element key, TreeNode* parent, TreeNode* left, TreeNode* right) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->key = key;
	node->parent = parent;
	node->left = left;
	node->right = right;

	return node;
}

int isRoot(TreeNode* node) {
	return node->parent == NULL;
}

int depth(TreeNode* node) {
	if (isRoot(node))
		return 0;
	else
		return 1 + depth(node->parent);
}

int isExternal(TreeNode* node) {

}

int height(TreeNode* node) {
	if (isExternal(node))
		return 0;
	else {
		int h = max(height(node->left)), height(node->right))
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

void levelOrder(TreeNode* node) {
	QueueType Q;
	init(&Q);

	enqueue(&Q, node);

	while (!isEmpty(&Q)) {
		node = dequeue(&Q);
		printf("[%c] ", node->key);

		if (node->left)
			enqueue(&Q, node->left);

		if (node->right)
			enqueue(&Q, node->right);
	}
}

int main() {
	TreeNode* n11 = makeNode('I', NULL, NULL, NULL);
	TreeNode* n10 = makeNode('H', NULL, NULL, NULL);
	TreeNode* n7 =  makeNode('G', NULL, NULL, NULL);
	TreeNode* n6 =  makeNode('F', NULL, NULL, NULL);
	TreeNode* n5 =  makeNode('E', NULL, n10, n11);
	TreeNode* n4 =  makeNode('D', NULL, NULL, NULL);
	TreeNode* n3 =  makeNode('C', NULL, n6, n7);
	TreeNode* n2 =  makeNode('B', NULL, n4, n5);
	TreeNode* n1 =  makeNode('A', NULL, n2, n3);
	
	n10->parent = n11->parent = n5;
	n6->parent = n7->parent = n3;
	n4->parent = n5->parent = n2;
	n2->parent = n3->parent = n1;

	printf("Pre : "); preOrder(n1); printf("\n");
	printf("In : "); inOrder(n1); printf("\n");
	printf("Post : "); postOrder(n1); printf("\n");

	printf("Level : "); levelOrder(n1); printf("\n");

	return 0;
}