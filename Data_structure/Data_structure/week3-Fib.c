#pragma warning(disable:4996)
#include <stdio.h>

int count;


// ���ȣ��
/*
T(n) = 2T(n - 1) + 1
	 = 2(2T(n - 2) + 1) + 1
	 = 2(2(2T(n - 3) + 1) + 1) + 1
	 ....

	 = O(2^n)

*/

// �Ǻ���ġ ���� ���� (3/ 20 ����)
// ������ �迭 �߰� : ������ n
// �迭�� �Ǻ���ġ 0, 1,2  .. �迭�� ����� ����(DP)
// �迭 ���� �̿��Ͽ� �ٽ� ������� �ʰ� ���(�޸������̼� - �������θ� ġ��ģ Ʈ��)
// ���� �ۼ� �ؾ���(�����ϰ� �ۼ�)

int rFib(int n) {
	count++;
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return rFib(n - 1) + rFib(n - 2);
}

int main() {
	int n;

	scanf("%d", &n);

	printf("%d - %d", rFib(n), count);

	return 0;
}