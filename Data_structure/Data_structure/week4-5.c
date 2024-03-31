#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

void in_mtx(int n, int m, int mtx[][100]) {
	int i, j;
	int pi = 0, pj = 0;
	int num = 1;

	mtx[pi][pj] = 1;

	while (pj + 1 < m && mtx[pi][pj + 1] == 0) {
		pj++;
		num++;
		i = pi;
		j = pj;

		mtx[i][j] = num;

		while (i + 1 < n && j - 1 >= 0 && mtx[i + 1][j - 1] == 0) {
			num++;
			mtx[i + 1][j - 1] = num;
			i++;
			j--;
		}
	}



	while (pi + 1 < n && mtx[pi + 1][pj] == 0) {
		pi++;
		num++;
		i = pi;
		j = pj;

		mtx[i][j] = num;

		while (i + 1 < n && j - 1 >= 0 && mtx[i + 1][j - 1] == 0) {
			num++;
			i++;
			j--;
			mtx[i][j] = num;
		}

	}
	
}

int main() {
	int N, M;
	int mtx[100][100];

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			mtx[i][j] = 0;

	in_mtx(N, M, mtx);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			printf(" %d", mtx[i][j]);
		printf("\n");
	}

	return 0;
}