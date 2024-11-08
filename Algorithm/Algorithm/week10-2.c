#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int n = 7;

void init(int** graph) {
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++)
			graph[i][j] = 0;
	}
}

int** createGraph() {
	int** graph = (int**)malloc(n * sizeof(int*));
	graph[0] = NULL;
	for (int i = 1; i < n; i++)
		graph[i] = (int*)malloc(n * sizeof(int));
	init(graph);

	graph[1][2] = 1;
	graph[1][3] = 1;
	graph[1][4] = 1;
	graph[1][6] = 2;

	graph[2][1] = 1;
	graph[2][3] = 1;

	graph[3][1] = 1;
	graph[3][2] = 1;
	graph[3][5] = 4;

	graph[4][1] = 1;

	graph[5][3] = 4;
	graph[5][5] = 4;
	graph[5][6] = 3;

	graph[6][1] = 2;
	graph[6][5] = 3;
	
	return graph;
}

void change_w(int* graph, int vertex, int w) {
	graph[vertex] = w;
}

void printGraph(int* graph) {
	for (int i = 1; i < n; i++) {
		if (graph[i] != 0)
			printf(" %d %d", i, graph[i]);
	}
	printf("\n");
}

int main() {
	int** graph = createGraph();

	while (1) {
		char cmd;
		scanf("%c", &cmd);

		if (cmd == 'a') {
			int numNode;
			scanf("%d", &numNode); getchar();
			if (numNode <= 6 && numNode >= 1) 
				printGraph(graph[numNode]);
			else printf("-1\n");
		}
		else if (cmd == 'm') {
			int v1, v2, w;
			scanf("%d %d %d", &v1, &v2, &w); getchar();
			if (v1 >= 1 && v2 >= 1 && v1 <= 6 && v2 <= 6) {
				change_w(graph[v1], v2, w);
				change_w(graph[v2], v1, w);
			}
			else printf("-1\n");
		}
		else if (cmd == 'q')
			break;
	}


	return 0;
}