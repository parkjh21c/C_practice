#include <stdio.h>
#include <stdlib.h>

#define N 13

typedef char element;

typedef struct TreeNode {
	element key;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

TreeNode* makeNode(element key, TreeNode* left, TreeNode* right) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->key = key;
	node->left = left;
	node->right = right;

	return node;
}

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

// 일반 변환
void changeTree(TreeNode* node) {
	if (node->left != NULL && node->right != NULL) {
		changeTree(node->left);
		changeTree(node->right);

		TreeNode* tmp;
		tmp = node->left;
		node->left = node->right;
		node->right = tmp;
	}
}

// 스택
/*
TreeNode* inverseTree(TreeNode* root) {
	StackType S;
	init(&S);

	TreeNode* p = root;

	if (p == NULL)
		return NULL;

	push(&S, p);

	while(!isEmpty(&S)){
		p = pop(&S);
		if (p->left != NULL && p->right != NULL){
			TreeNode *left = p->left;
			TreeNode *right = p->right;

			p->left = right;
			p->right = left;

			push(&S, p->left);
			push(&S, p->right);
		}
	}
	return root;
}
*/
// 큐 변환
void QchangeTree(TreeNode* node) {
	QueueType Q;
	init(&Q);
	
	TreeNode* p = node;
	enqueue(&Q, p);

	while (!isEmpty(&Q)) {
		p = dequeue(&Q);

		if (p->left != NULL && p->right != NULL) {
			TreeNode* left = p->left;
			TreeNode* right = p->right;

			p->left = right;
			p->right = left;

			enqueue(&Q, p->left);
			enqueue(&Q, p->right);
		}
		
	}
}

int main() {
	TreeNode* n11 = makeNode('I', NULL, NULL);
	TreeNode* n10 = makeNode('H', NULL, NULL);
	TreeNode* n7 = makeNode('G', NULL, NULL);
	TreeNode* n6 = makeNode('F', NULL, NULL);
	TreeNode* n5 = makeNode('E', n10, n11);
	TreeNode* n4 = makeNode('D', NULL, NULL);
	TreeNode* n3 = makeNode('C', n6, n7);
	TreeNode* n2 = makeNode('B', n4, n5);
	TreeNode* n1 = makeNode('A', n2, n3);

	printf("pre : "); preOrder(n1); printf("\n");
	changeTree(n1);
	printf("after : "); preOrder(n1); printf("\n");

	QchangeTree(n1);
	printf("aaff : "); preOrder(n1); printf("\n");

	return 0;
}