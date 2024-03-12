#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ���� O(n2) �ð����⵵ �̹Ƿ� �� ���� ���� �ʿ��� 
// 1181�� ���� 
void swap(char* a, char* b);

int main() {
	int N;
	char** word = NULL, * tmp = NULL;

	scanf("%d", &N);

	word = (char**)malloc(N * sizeof(char*));
	if (word == NULL) return -1;

	// �Է¹ޱ�
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
			// ���̰� ª�� ��
			else if (strlen(word[i]) > strlen(word[j])) 
				swap(word[i], word[j]);
			
			// ���̰� ���� ��
			else {
				// ���� �ܾ��� ��
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