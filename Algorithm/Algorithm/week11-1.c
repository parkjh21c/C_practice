#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int n;
// 정점 개수

typedef struct GraphNode {
	struct GraphNode* link;
	int vertex;
	int visit;
}GraphNode;

GraphNode* makeNode(int vertex) {
	GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = vertex;
	node->link = NULL;
	node->visit = 0;
	return node;
}

void initGraph(GraphNode** graph) {
	for (int i = 1; i <= n; i++)
		graph[i] = makeNode(i);
}

void addNode(GraphNode** graph, int v1, int v2) {
	GraphNode* p;
	GraphNode* q;

	p = graph[v1];
	for (; p->link != NULL && p->link->vertex < v2; p = p->link);
	if (p->link == NULL || p->link->vertex != v2) {
		q = makeNode(v2);
		q->link = p->link;
		p->link = q;
	}

	p = graph[v2];
	for (; p->link != NULL && p->link->vertex < v1; p = p->link);
	if (p->link == NULL || p->link->vertex != v1) {
		q = makeNode(v1);
		q->link = p->link;
		p->link = q;
	}
}

void initVisit(GraphNode** graph) {
	for (int i = 1; i <= n; i++)
		graph[i]->visit = 0;
}

void DFS(GraphNode** graph, int s) {
	GraphNode* p = graph[s];
	if (p->visit == 1) return;

	p->visit = 1;
	printf("%d\n", p->vertex);

	for (GraphNode* q = p->link; q != NULL; q = q->link) {
		if (graph[q->vertex]->visit == 0)
			DFS(graph, q->vertex);
	}
}

int main() {
	int m, s;

	scanf("%d %d %d", &n, &m, &s);

	GraphNode** graph = (GraphNode**)malloc((n + 1) * sizeof(GraphNode*));
	initGraph(graph);

	for (int i = 0; i < m; i++) {
		int v1, v2;
		scanf("%d %d", &v1, &v2);

		addNode(graph, v1, v2);
	}

	initVisit(graph);
	DFS(graph, s);

	return 0;
}