#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1181�� ����

int main() {
	int N;
	char** word = NULL;

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

	for (int i = 0; i < N - 1; i++) {
		int len = strlen(word[i]);
		for (int j = i + 1; j < N; j++) {
			// ���̰� ª�� ��
			if (len > strlen(word[j])) {

			}
			// ���̰� ���� ��
			else if (len == strlen(word[j])) {

			}
		}
	}


	for (int i = 0; i < N; i++)
		printf("%s\n", word[i]);

	// swap �Լ� ����� ���ǿ� ���� ����

	// �ߺ��ܾ�� ����� �� �ǳ� �ٴ� ������� ���



	return 0;
}