#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>


int findKey(int* key, int k, int first, int last) {
	int index;


	if (first > last)
		return last;
	else if (first == last) {
		if (key[first] <= k)
			return first;
		else
			return first -1;
	}

	index = (first + last) / 2;

	if (key[index] == k)
		return index;

	else if (key[index] > k)
		return findKey(key, k, first, index - 1);

	else
		return findKey(key, k, index + 1, last);
}

int main() {
	int n, k;

	scanf("%d %d", &n, &k);

	int* key = NULL;

	key = (int*)malloc(n * sizeof(int));
	if (key == NULL) return -1;

	// 정렬 되어 있는 수 받기
	for (int i = 0; i < n; i++)
		scanf("%d", &key[i]);

	printf(" %d", findKey(key, k, 0, n - 1));

	return 0;
}