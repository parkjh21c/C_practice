#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int findKey(int* key, int n,int k) {
	int first, last;

	first = 0;
	last = n - 1;

	while (first <= last) {
		int mid = (first + last) / 2;

		if (key[mid] == k)
			return mid;
		else if (key[mid] > k) 
			last = mid - 1;
		else 
			first = mid + 1;
	}
	
	return first;
}

int main() {
	int n, k;

	scanf("%d %d", &n, &k);

	int* key = NULL;

	key = (int*)malloc(n * sizeof(int));
	if (key == NULL) return -1;

	for (int i = 0; i < n; i++)
		scanf("%d", &key[i]);

	int z = findKey(key, n, k);

	printf("%d", z);
	return 0;
}