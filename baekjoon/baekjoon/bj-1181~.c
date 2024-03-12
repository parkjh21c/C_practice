#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 현제 O(n2) 시간복잡도 이므로 더 빠른 정렬 필요함 
// 1181번 문제 
void swap(char* a, char* b);

int main() {
	int N;
	char** word = NULL, * tmp = NULL;

	scanf("%d", &N);

	word = (char**)malloc(N * sizeof(char*));
	if (word == NULL) return -1;

	// 입력받기
	for (int i = 0; i < N; i++) {
		char ch[50];
		scanf("%s", ch);

		word[i] = (char*)malloc((strlen(ch) + 1) * sizeof(char));
		if (word[i] == NULL) return -1;

		strcpy(word[i], ch);
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (strlen(word[i]) < strlen(word[j]))
				continue;
			// 길이가 짧을 때
			else if (strlen(word[i]) > strlen(word[j])) 
				swap(word[i], word[j]);
			
			// 길이가 같을 때
			else {
				// 같은 단어일 때
				if (strcmp(word[i], word[j]) == 0) {
					swap(word[N - 1], word[j]);
					N--;
				}
				else if (strcmp(word[i], word[j]) > 0) {
					swap(word[i], word[j]);
				}
			}
		}
		printf("%s\n", word[i]);
		free(word[i]);
	}

	free(word);

	return 0;
}

void swap(char* a, char* b) {
	char* tmp;

	tmp = a;
	a = b;
	b = tmp;
}