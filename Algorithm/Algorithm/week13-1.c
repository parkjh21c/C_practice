#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int index;
	struct node* next;
}NODE;

typedef struct vertex {
	int id;
	int d;
	int p;
	NODE* adj_list;
}VERTEX;

typedef struct edge {
	int a;
	int b;
	int weight;
}EDGE;

typedef struct graph {
	VERTEX* vertices;
	EDGE* edges;
}GraphType;

typedef struct queue {
	int max;
	int size;
	int* key;
	int* value;

}QUEUE;

QUEUE Q;
GraphType G;
int n, m;

NODE* get_node(int i) {
	NODE* node = (NODE*)malloc(sizeof(NODE));
	node->index = i;
	node->next = NULL;

	return node;
}

int opposite(NODE* e, int a) {
	EDGE edge = G.edges[e->index];
	if (edge.a == a) 
		return edge.b;
	else 
		return edge.a;
}

void insertAdj(int id, int a, int b) {
	NODE* head = G.vertices[a].adj_list;
	NODE* node = get_node(id);

	while (head->next != NULL) 
		head = head->next;
	
	head->next = node;
}

void edgeMethod(int id, int a, int b, int w) {
	G.edges[id].a = a;
	G.edges[id].b = b;
	G.edges[id].weight = w;
	insertAdj(id, a, b);
	if (a != b)
		insertAdj(id, b, a);
}

int isEmpty() {
	return Q.size == 0;
}

void makequeue(int size) {
	Q.max = size;
	Q.size = 0;
	Q.key = (int*)malloc(sizeof(int) * size);
	Q.value = (int*)malloc(sizeof(int) * size);
}

void enqueue(int key, int val) {
	int size = Q.size;
	Q.key[size] = key;
	Q.value[size] = val;
	Q.size++;
}

int dequeue() {
	int minkey, minval;
	int minidx = 0;
	
	minkey = Q.key[0];
	minval = Q.value[0];
	minidx = 0;

	for (int i = 1; i < Q.max; i++) {
		if (Q.key[i] < minkey) {
			minkey = Q.key[i];
			minval = Q.value[i];
			minidx = i;
		}
	}
	Q.key[minidx] = 100000;
	Q.value[minidx] = -1;
	Q.size--;
	return minval;
}

void replaceKey(int target, int key) {
	for (int i = 0; i < Q.max; i++) {
		if (Q.value[i] == target) {
			Q.key[i] = key;
		}
	}
}

int find(int target) {
	for (int i = 0; i < Q.max; i++) {
		if (Q.value[i] == target) {
			return 1;
		}
	}

	return 0;
}


void PrimJarnikMST(int start) {

	for (int i = 1; i <= n; i++) {
		G.vertices[i].d = 100000;
		G.vertices[i].p = -1;
	}
	G.vertices[start].d = 0;

	makequeue(n);
	for (int i = 1; i <= n; i++) {
		enqueue(G.vertices[i].d, i);
	}

	int v = -1;
	int w;
	int e;

	NODE* temp;
	int res = 0;
	while (!isEmpty()) {
		v = dequeue();
		printf(" %d", v);
		res = res + G.vertices[v].d;
		temp = G.vertices[v].adj_list;
		while (temp->next) {
			w = opposite(temp->next, v);
			e = (temp->next->index);
			if (find(w) && G.edges[e].weight < G.vertices[w].d) {
				G.vertices[w].p = v;
				G.vertices[w].d = G.edges[e].weight;
				replaceKey(w, G.vertices[w].d);
			}
			temp = temp->next;
		}
	}
	printf("\n%d", res);
}

int main() {
	scanf("%d %d", &n, &m);

	G.edges = (EDGE*)malloc(m * sizeof(EDGE));
	G.vertices = (VERTEX*)malloc((n + 1) * sizeof(VERTEX));

	for (int i = 1; i <= n; i++) {
		G.vertices[i].id = i;
		G.vertices[i].adj_list = get_node(-1);
	}

	int a, b, w;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &w);
		edgeMethod(i, a, b, w);
	}

	PrimJarnikMST(1);

	return 0;
}