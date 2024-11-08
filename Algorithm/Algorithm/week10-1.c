#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

#define MAX_link 21

int n = 7;

typedef struct GraphNode {
	int vertex;
	int w;
	struct GraphNode* link;
}GraphNode;

GraphNode* makeNode(int vertex, int w) {
	GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = vertex;
	node->w = w;
	node->link = NULL;

	return node;
}

void initGraph(GraphNode** graph) {
	graph[0] = NULL;
	for (int i = 1; i < n; i++)
		graph[i] = makeNode(i, 0);
	graph[1]->link = makeNode(2, 1);
	graph[1]->link->link = makeNode(3, 1);
	graph[1]->link->link->link = makeNode(4, 1);
	graph[1]->link->link->link->link = makeNode(6, 2);

	graph[2]->link = makeNode(1, 1);
	graph[2]->link->link = makeNode(3, 1);

	graph[3]->link = makeNode(1, 1);
	graph[3]->link->link = makeNode(2, 1);
	graph[3]->link->link->link = makeNode(5, 4);

	graph[4]->link = makeNode(1, 1);

	graph[5]->link = makeNode(3, 4);
	graph[5]->link->link = makeNode(5, 4);
	graph[5]->link->link->link = makeNode(6, 3);

	graph[6]->link = makeNode(1, 2);
	graph[6]->link->link = makeNode(5, 3);
}

void deleteNode(GraphNode* node) {
	GraphNode* p = node->link;
	node->link = p->link;
	free(p);
}

void addNode(GraphNode* node, int vertex, int w) {
	GraphNode* p = node;

	for (; p->link != NULL && p->link->vertex < vertex; p = p->link);

	if (w == 0)
		deleteNode(p);
	else if (p->link == NULL) 
		p->link = makeNode(vertex, w);
	else if (p->link->vertex == vertex) {
		p = p->link;
		p->w = w;
	}
	else {
		GraphNode* tmp = makeNode(vertex, w);
		tmp->link = p->link;
		p->link = tmp;
	}
}

void printGraph(GraphNode* node) {
	GraphNode* p = node->link;

	for (; p != NULL; p = p->link) 
		printf(" %d %d", p->vertex, p->w);
	printf("\n");
}


int main() {
	GraphNode** graph = (GraphNode**)malloc(n*sizeof(GraphNode*));
	initGraph(graph);

	while (1) {
		char cmd;
		scanf("%c", &cmd);

		if (cmd == 'a') {
			int numNode;
			scanf("%d", &numNode); getchar();
			if (numNode <= 6 && numNode >= 1) {
				GraphNode* tmp = graph[numNode];
				printGraph(tmp);
			}
			else printf("-1\n");
		}
		else if (cmd == 'm') {
			int v1, v2, w;
			scanf("%d %d %d", &v1, &v2, &w); getchar();
			if (v1 >= 1 && v2 >= 1 && v1 <= 6 && v2 <= 6) {
				addNode(graph[v1], graph[v2]->vertex, w);
				if (v1 == v2) continue;
				addNode(graph[v2], graph[v1]->vertex, w);
			}
			else printf("-1\n");
		}
		else if (cmd == 'q')
			break;
	}

	for (int i = 1; i < n; i++) {
		GraphNode* p = graph[i];
		while (p != NULL) {
			GraphNode* tmp = p;
			p = p->link;
			free(tmp);
		}
	}
	free(graph);

	return 0;
}