#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000
int Limits[] = { 1, 100, 500, 1000 };
int mode;
int Limit;

void createArray(int* A) {
    for (int i = 0; i < N; i++) {
        A[i] = rand() % N + 1;
    }
}

int findPivot(int* A, int l, int r) {
    if (mode == 0) return r; // deterministic1
    if (mode == 2) return l + rand() % (r - l + 1); // randomized1
    int a, b, c;
    if (mode == 1) { // deterministic3
        a = l;
        b = (l + r) / 2;
        c = r;
    }
    else { // randomized3
        a = l + rand() % (r - l + 1);
        b = l + rand() % (r - l + 1);
        c = l + rand() % (r - l + 1);
    }
    if ((A[a] <= A[b] && A[b] <= A[c]) || (A[c] <= A[b] && A[b] <= A[a])) return b;
    if ((A[b] <= A[a] && A[a] <= A[c]) || (A[c] <= A[a] && A[a] <= A[b])) return a;
    return c;
}

void inPlacePartition(int* A, int l, int r, int pivot, int* a, int* b) {
    int pivotValue = A[pivot];
    int i = l, j = r;
    while (i <= j) {
        while (A[i] < pivotValue) i++;
        while (A[j] > pivotValue) j--;
        if (i <= j) {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i++; j--;
        }
    }
    *a = j;
    *b = i;
}

void rQuickSort(int* A, int l, int r) {
    if (r - l >= Limit) {
        int pivot = findPivot(A, l, r);
        int a, b;
        inPlacePartition(A, l, r, pivot, &a, &b);
        rQuickSort(A, l, a);
        rQuickSort(A, b, r);
    }
}

void insertionSort(int* A, int n) {
    for (int i = 1; i < n; i++) {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

void quickSort(int* A, int n) {
    rQuickSort(A, 0, n - 1);
    if (Limit > 1) insertionSort(A, n);
}

void printCPUTime(clock_t start, clock_t end) {
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    printf("%10.8f ", cpu_time_used);
}

int main() {
    srand(time(0));
    int* A = (int*)malloc(N * sizeof(int));

    printf("Limit\t 결정적1\t 결정적3\t 무작위1\t 무작위3\n");
    for (int i = 0; i < sizeof(Limits) / sizeof(Limits[0]); i++) {
        Limit = Limits[i];
        printf("%d\t", Limit);
        for (mode = 0; mode < 4; mode++) {
            createArray(A);
            int* A_copy = (int*)malloc(N * sizeof(int));
            for (int j = 0; j < N; j++) A_copy[j] = A[j];

            clock_t start = clock();
            quickSort(A_copy, N);
            clock_t end = clock();
            printCPUTime(start, end);

            free(A_copy);
        }
        printf("\n");
    }

    free(A);
    return 0;
}
