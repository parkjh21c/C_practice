#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

typedef struct List {
	int* data;
	int count;
} List;

void init(List* L, int n) {
	L->data = (int*)malloc(sizeof(int) * n);
	L->count = 0;
}

void addNode(List* L, int data) {
	L->data[L->count++] = data;
}

// 힙 생성 함수
void minHeapify(int* heap, int n, int i) {
	int smallest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && heap[left] < heap[smallest])
		smallest = left;
	if (right < n && heap[right] < heap[smallest])
		smallest = right;
	if (smallest != i) {
		int temp = heap[i];
		heap[i] = heap[smallest];
		heap[smallest] = temp;
		minHeapify(heap, n, smallest);
	}
}

void buildMinHeap(int* heap, int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		minHeapify(heap, n, i);
}

// k번째 작은 원소 찾기
int findKthSmallest(List* L, int n, int k) {
	buildMinHeap(L->data, n);

	int result;
	for (int i = 0; i < k; i++) {
		result = L->data[0];
		L->data[0] = L->data[n - 1];
		n--;
		minHeapify(L->data, n, 0);
	}
	return result;
}

List* buildList(int n, int min, int max) {
	List* L = (List*)malloc(sizeof(List));
	init(L, n);
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

	for (int i = 0; i < 10; i++) {
		printf(" %d", L->data[i]);
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