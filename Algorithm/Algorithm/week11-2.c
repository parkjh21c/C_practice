#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int n;
// 정점 개수

typedef struct Node {
	int data;
	struct Node* next;
}Node;

typedef struct Queue {
	Node* front, * rear;
	int s;
}Queue;

void init(Queue *Q) {
	Q->front = NULL;
	Q->rear = NULL;
	Q->s = 0;
}

int isEmpty(Queue* Q) {
	return Q->front == NULL;
}

void enqueue(Queue* Q, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->next = NULL;
	node->data = data;

	if (Q->front == NULL) {
		Q->front = node;
		Q->rear = node;
	}
	else {
		Q->rear->next = node;
		Q->rear = node;
	}
	Q->s++;
}

int dequeue(Queue* Q) {
	if (Q->front == NULL) return -1;

	Node* tmp = Q->front;
	int d_data = tmp->data;
	Q->front = Q->front->next;

	if (Q->front == NULL)
		init(Q);
	free(tmp);
	Q->s--;
	return d_data;
}

int** initGraph() {
	int** graph = (int**)malloc((n + 1) * sizeof(int*));
	for (int i = 0; i <= n; i++)
		graph[i] = (int*)malloc((n + 1) * sizeof(int));

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++)
			graph[i][j] = 0;
	}

	return graph;
}

void BFS(int** graph, int s) {
	Queue Q;
	init(&Q);

	enqueue(&Q, s);
	graph[s][0] = 1;

	while (!isEmpty(&Q)) {
		int c = dequeue(&Q);
		printf("%d\n", c);

		for (int i = 1; i <= n; i++) {
			if (graph[c][i] == 1 && graph[i][0] != 1) {
				enqueue(&Q, i);
				graph[i][0] = 1;
			}
		}
	}


}

void addVertex(int** graph, int v1, int v2) {
	graph[v1][v2] = 1;
	graph[v2][v1] = 1;
}

int main() {
	int m, s;

	scanf("%d %d %d", &n, &m, &s);

	int** graph = initGraph();

	for (int i = 0; i < m; i++) {
		int v1, v2;
		scanf("%d %d", &v1, &v2);

		addVertex(graph, v1, v2);
	}

	BFS(graph, s);

	return 0;
}