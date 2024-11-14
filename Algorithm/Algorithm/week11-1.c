#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct GraphNode {
	struct GraphNode* link;
	int vertex;
}GraphNode;

GraphNode* makeNode(int vertex) {
	GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = vertex;
	node->link = NULL;
	return node;
}

int main() {
	int n, m, s;

	scanf("%d %d %d", &n, &m & s);

	return 0;
}