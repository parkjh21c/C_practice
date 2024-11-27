#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

int MAX = 30;
int* A, * H;
int n, s, d;
int mincost;
int version = 0;
LARGE_INTEGER ticksPerSec;
LARGE_INTEGER start, end, diff;

int rAirtelDC(int n, int s, int d) {
	if (d - s == 0) return 0;
	int cost;
	int mcost = A[d - s];
	for (int i = 1; i < d - s; i++) {
		cost = rAirtelDC(n, s, d - i) + H[d - i] + A[i];
		mcost = min(mcost, cost);
	}

	return mcost;
}

// divide and conquer
void airtelDC(int n, int s, int d){
	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);

	mincost = rAirtelDC(n, s, d);
	version = 0;
	QueryPerformanceCounter(&end);
}

// dynamic programming
void airtelDP(int n, int s, int d) {
	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	int cost = 0;
	int* m = (int*)malloc(n * sizeof(int));
	m[s] = 0;

	for (int i = s; i < n; i++) {
		m[i] = A[i - s];
		for (int j = s; j < i; j++) {
			cost = m[j] + H[j] + A[i - j];
			m[i] = min(m[i], cost);
		}
	}

	version = 1;
	mincost = m[d];

	QueryPerformanceCounter(&end);
}

void printCPUTime() {
	printf("%d\t%d\t%d\t%d\t", n, s, d, mincost);
	if (version == 0) printf("DC\t");
	else printf("DP\t");
	diff.QuadPart = end.QuadPart - start.QuadPart;
	double t = (double)diff.QuadPart / (double)ticksPerSec.QuadPart;
	printf("%.8f\n", t);
}

int main() {
	A = (int*)malloc(MAX * sizeof(int)); // 도시
	H = (int*)malloc(MAX * sizeof(int)); // 숙박 요금

	A[0] = 0;
	A[1] = 1;
	
	for (int i = 2; i < MAX; i++)
		A[i] = A[i - 1] + A[i - 1] % 5 + 3;

	H[0] = 0;
	H[1] = 5;

	for (int i = 2; i < MAX; i++)
		H[i] = (H[i - 1] + i) % 9 + 1;

	printf("n\ts\td\tmincost\t version\t cputime\n");

	n = 6;
	int s_l[3] = { 0, 2, 2 };
	int d_l[3] = { 4, 5, 4 };

	for (int i = 0; i < 3; i++) {
		s = s_l[i], d = d_l[i];
		airtelDC(n, s, d);
		printCPUTime();
		airtelDP(n, s, d);
		printCPUTime();
	}

	n = MAX;
	s = 1, d = n - 2;
	airtelDC(n, s, d);
	printCPUTime();
	airtelDP(n, s, d);
	printCPUTime();
	
	
	return 0;
}