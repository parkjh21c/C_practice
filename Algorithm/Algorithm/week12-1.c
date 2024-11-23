#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	struct node* next;
	int index;
}node;

typedef struct vertex {
	char vertex;
	struct node* outEdges;
	struct node* inEdges;
	int inDegree;
}vertex;

typedef struct edge {
	int a, b, id;
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
int* topOrder;	// n+1Å©±â

node* makeNode(int index) {
	node* new_node = (node*)malloc(sizeof(node));
	new_node->next = NULL;
	new_node->index = index;
	return new_node;
}

void initializeGraph() {
	G.vertices = (vertex*)malloc(n * sizeof(vertex));
	topOrder = (int*)malloc((n + 1) * sizeof(int));
	Q.queue = (int*)malloc(n * sizeof(int));
}

void buildGraph() {
	scanf("%d", &n); 
	initializeGraph();

	for (int i = 0; i < n; i++) {
		char vName;
		scanf("%c", &vName); getchar();
		insertVertex(vName, i);
	}
}

int main() {

	buildGraph();
	
	topologicalSort();

	if (topOrder[0] == 0)

	return 0;
}