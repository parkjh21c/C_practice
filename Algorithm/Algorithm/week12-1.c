#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct GraphNode {
	char data;
	struct GraphNode* link;
}GraphNode;

int n, m;
GraphNode** G;

void initializeGraph() {
	G = (GraphNode**)malloc(n * sizeof(GraphNode*));
	for (int i = 0; i < n; i++)
		G[i] = (GraphNode*)malloc(m * sizeof(GraphNode));
}

GraphNode** buildGraph(GraphNode** G) {
	initializeGraph();
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		char vertex;
		scanf("%c", &vertex); getchar();
		insertVertex(vertex, i);
	}
	return G;
}

int main() {
	
	buildGraph();

	scanf("%d", &l);

	for (int i = 0; i < l; i++) {
		char v1, v2;
		scanf("%c %c", &v1, &v2); getchar();
	}

	return 0;
}