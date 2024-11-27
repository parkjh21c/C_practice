#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	struct node* next;
	int index;
}node;

typedef struct vertex {
	char vertex;
	node* outEdges;
	node* inEdges;
	int inDegree;
}vertex;

typedef struct edge {
	int origin;
	int destination;
}edge;

typedef struct graph {
	vertex* vertices;
	edge* edges;
}graph;

typedef struct Queue {
	int front;
	int rear;
	int* queue;
}Queue;

graph G;
Queue Q;
int n, m;
int* in;
int* topOrder;	// n+1크기

node* makeNode(int index) {
	node* new_node = (node*)malloc(sizeof(node));
	new_node->next = NULL;
	new_node->index = index;
	return new_node;
}

void initQueue() {
	Q.front = 0;
	Q.rear = n - 1;
}

int isEmpty() {
	return Q.front == (Q.rear + 1) % n;
}

void enqueue(int i) {
	Q.rear = (Q.rear + 1) % n;
	Q.queue[Q.rear] = i;
}

int dequeue() {
	if (!isEmpty()) {
		int deq = Q.queue[Q.front];
		Q.front = (Q.front + 1) % n;
		return deq;
	}
	printf("queue error\n");
	return -1;
}

void addFirst(node* H, int i) {
	node* _node = makeNode(i);
	_node->next = H->next;
	H->next = _node;
}

void initializeGraph() {
	G.vertices = (vertex*)malloc((n + 1) * sizeof(vertex));
	topOrder = (int*)malloc((n + 1) * sizeof(int));
	Q.queue = (int*)malloc(n * sizeof(int));
	in = (int*)malloc((n + 1) * sizeof(int));
}

void insertVertex(char vName, int i) {
	G.vertices[i].vertex = vName;
	G.vertices[i].inEdges = makeNode(-1);
	G.vertices[i].outEdges = makeNode(-1);
	G.vertices[i].inDegree = 0;
}

int index(char vName) {
	for (int i = 1; i <= n; i++) {
		if (G.vertices[i].vertex == vName)
			return i;
	}
}

void insertDirectedEdge(char uName, char wName, int i) {
	int u, w;

	u = index(uName);
	w = index(wName);

	G.edges[i].origin = u;
	G.edges[i].destination = w;

	addFirst(G.vertices[u].outEdges, i);
	addFirst(G.vertices[w].inEdges, i);

	G.vertices[w].inDegree += 1;
}

void buildGraph() {
	scanf("%d", &n); getchar();
	initializeGraph();

	for (int i = 1; i <= n; i++) {
		char vName;
		scanf("%c", &vName); getchar();
		insertVertex(vName, i);
	}

	scanf("%d", &m); getchar();
	G.edges = (edge*)malloc(m * sizeof(edge));

	for (int i = 0; i < m; i++) {
		char uName, wName;
		scanf("%c %c", &uName, &wName); getchar();
		insertDirectedEdge(uName, wName, i);
	}
}

void topologicalSort() {
	initQueue();

	for (int i = 1; i <= n; i++) {
		in[i] = G.vertices[i].inDegree;
		if (in[i] == 0)
			enqueue(i);
	}
	
	int t = 1; // 위상 순위

	while (!isEmpty()) {
		int u = dequeue();
		topOrder[t] = u;
		t += 1;

		node* p = G.vertices[u].outEdges->next;
		for (; p != NULL; p = p->next) {
			int w = G.edges[p->index].destination;
			in[w] = in[w] - 1;
			if (in[w] == 0)
				enqueue(w);
		}
	}
	if (t <= n)
		topOrder[0] = 0;
	else
		topOrder[0] = 1;
}

int main() {

	buildGraph();
	
	topologicalSort();

	if (topOrder[0] == 0)
		printf("0");
	else {
		for (int i = 1; i <= n; i++)
			printf("%c ", G.vertices[topOrder[i]].vertex);
	}
	return 0;
}