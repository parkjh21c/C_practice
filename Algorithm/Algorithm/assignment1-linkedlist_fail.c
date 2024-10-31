#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

typedef struct Node {
	struct Node* next;
	int data;
}Node;

typedef struct List {
	Node* head;
	Node* tail;
	int count;
}List;

typedef struct Heap {
	Node* head;
}Heap;

void init(List* L) {
	L->head = NULL;
	L->tail = NULL;
	L->count = 0;
}

void addNode(List* L, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->next = NULL;
	node->data = data;

	if (L->head == NULL) {
		L->head = L->tail = node;
		L->count += 1;
	}
	else {
		Node* p = L->head;
		for (; p != L->tail; p = p->next);

		p->next = node;
		L->tail = node;
		L->count += 1;
	}
}

int removeFirstNode(List* L) {
	Node* p = L->head;

	if (L->head == NULL) {
		printf("Empty!\n");
	}
	else if (L->head == L->tail) {
		int data = p->data;
		free(p);
		init(L);
		return data;
	}
	else {
		int data = p->data;
		L->head = p->next;
		free(p);
		return data;
	}
}

void insertHeap(Heap* H, int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	if (H->head == NULL || H->head->data > data) {
		node->next = H->head;
		H->head = node;
	}
	else {
		Node* p = H->head;
		for (; p->next != NULL && p->next->data < data; p = p->next);
		node->next = p->next;
		p->next = node;
	}
}

Heap* heapSort(List* L) {
	Heap *H = (Heap*)malloc(sizeof(Heap));
	H->head = NULL;
	
	Node* p = L->head;
	for (; p != L->tail; p = p->next) 
		insertHeap(H, p->data);	

	return H;
}

// n + klogn -> 최소 힙정렬
int findKthSmallest(List *L, int n, int k) {
	// 1. 최소 힙 형태로 만들기
	Heap* H = heapSort(L);

	// 2. k번째 반환
	Node* p = H->head;
	for (int i = 1; i < k; i++)
		p = p->next;

	return p->data;
}

List* buildList(int n, int min, int max) {
	List *L = (List*)malloc(sizeof(List));
	init(L);
	for (int i = 0; i < n; i++) {
		int d = rand() % (max - min + 1) + min;
		addNode(L, d);
	}

	return L;
}

int main() {
	List* L;
	srand(time(NULL));
	L = buildList(10, 1, 100);

	Node* p = L->head;
	for (int i = 0; i < 10; i++) {
		printf(" %d", p->data);
		p = p->next;
	}
	printf("\n");

	int output[4];
	for (int k = 1; k <= 3; k++) 
		output[k] = findKthSmallest(L, 10, k);
	
	printf("%d %d %d\n", output[1], output[2], output[3]);

	L = buildList(100000, 1, 1000000);

	int k[4] = { 1, 100, 99900, 99999 };

	for (int i = 0; i < 4; i++) {
		LARGE_INTEGER ticksPerSec;
		LARGE_INTEGER start, end, diff;

		QueryPerformanceFrequency(&ticksPerSec);
		QueryPerformanceCounter(&start);
		int e = findKthSmallest(L, 100000, k[i]);
		QueryPerformanceCounter(&end);
		diff.QuadPart = end.QuadPart - start.QuadPart;
		double t = (double)diff.QuadPart / (double)ticksPerSec.QuadPart;
		printf("%d %.12f\n", e, t);
	}

	return 0;
}