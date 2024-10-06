#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int inPlacePartition(int* arr, int left, int right, int pivot_index) {
    int pivot_value = arr[pivot_index];
    int temp;
    temp = arr[pivot_index];
    arr[pivot_index] = arr[right];
    arr[right] = temp;

    int store_index = left;

    for (int i = left; i < right; i++) {
        if (arr[i] < pivot_value) {
            temp = arr[i];
            arr[i] = arr[store_index];
            arr[store_index] = temp;
            store_index++;
        }
    }

    temp = arr[store_index];
    arr[store_index] = arr[right];
    arr[right] = temp;

    return store_index;
}

int findPivot(int left, int right) {
    return left + rand() % (right - left + 1); 
}

void inPlaceQuickSort(int* arr, int left, int right) {
    if (left < right) {
        int k = findPivot(left, right);
        int pivot_new_index = inPlacePartition(arr, left, right, k);

        inPlaceQuickSort(arr, left, pivot_new_index - 1);
        inPlaceQuickSort(arr, pivot_new_index + 1, right);
    }
}

int main() {
    int n;
    int* arr = NULL;

    scanf("%d", &n);
    
    arr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]);
    

    srand(time(NULL));

    inPlaceQuickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]);   

    return 0;
}
