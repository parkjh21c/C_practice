#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1181번 문제

int main() {
	int N;
	char** word = NULL;

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

	for (int i = 0; i < N - 1; i++) {
		int len = strlen(word[i]);
		for (int j = i + 1; j < N; j++) {
			// 길이가 짧을 때
			if (len > strlen(word[j])) {

			}
			// 길이가 같을 때
			else if (len == strlen(word[j])) {

			}
		}
	}


	for (int i = 0; i < N; i++)
		printf("%s\n", word[i]);

	// swap 함수 만들고 조건에 맞춰 정렬

	// 중복단어는 출력할 때 건너 뛰는 방식으로 출력



	return 0;
}