#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

void in_matrix(int n, int m, int mtx[][100]) {
	int r = (int)(n / 2.0 + 0.5);
	int c = 0, check = n * m + 1;
	int row = 0, col = -1, num = 1;

	for (int i = 0; i < r; r++, c++) {
		// 위
		for (col++; col < m; col++, num++) 
			mtx[row][col] = num;
		col--;

		if (num == check)
			break;

		// 오른쪽(아래 방향)
		for (row++; row < n; row++, num++)
			mtx[row][col] = num;
		row--;
		m--;

		if (num == check)
			break;

		// 아래(왼쪽으로)
		for (col--; col >= c; col--, num++)
			mtx[row][col] = num;
		col++;
		n--;

		if (num == check)
			break;

		// 왼쪽(위쪽으로)
		for (row--; row > c; row--, num++)
			mtx[row][col] = num;
		row++;

		if (num == check)
			break;
	}
}

int main() {
	int N, M;
	int mtx[100][100];

	scanf("%d %d", &N, &M);
	
	in_matrix(N, M, mtx);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			printf(" %d", mtx[i][j]);
		printf("\n");
	}
	return 0;
}