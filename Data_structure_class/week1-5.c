#pragma warning(disable:4996)
#include <stdio.h>

struct time {
	int hour, min, sec;
};

int main() {
	struct time t1[2];
	int h, m, s;

	for (int i = 0; i < 2; i++) 
		scanf("%d %d %d", &t1[i].hour, &t1[i].min, &t1[i].sec);
	
	h = t1[1].hour - t1[0].hour;
	m = t1[1].min - t1[0].min;
	s = t1[1].sec - t1[0].sec;

	if (s < 0) {
		s += 60;
		m -= 1;
	}
	if (m < 0) {
		m += 60;
		h -= 1;
	}

	printf("%d %d %d", h, m, s);

	return 0;
}