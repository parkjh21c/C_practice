#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct GraphNode {
	char vertex;
	struct GraphNode* outEdges;
	struct GraphNode* inEdges;
	int inDegree;
}GraphNode;

int n, m;
GraphNode** G;

void initializeGraph() {
	G = (GraphNode**)malloc(n * sizeof(GraphNode*));
	for (int i = 0; i < n; i++)
		G[i] = (GraphNode*)malloc(m * sizeof(GraphNode));
}

void insertVertex(char vertex, int i) {
	G[i]->vertex = vertex;
	G[i]->outEdges = NULL;
	G[i]->inEdges = NULL;
	G[i]->inDegree = 0;
}

void buildGraph() {
	initializeGraph();
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		char vertex;
		scanf("%c", &vertex); getchar();
		insertVertex(vertex, i);
	}
}

void topologicalSort() {

}

int main() {
	
	buildGraph();

	topologicalSort();

	scanf("%d", &l);

	for (int i = 0; i < l; i++) {
		char v1, v2;
		scanf("%c %c", &v1, &v2); getchar();
	}

	return 0;
}