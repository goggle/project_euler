/*
 * Project Euler: Problem 45
 */
#include <stdio.h>

int main(void)
{
	unsigned int n, m, l;
	unsigned int T, P, H;

	n = 285;
	m = 165;
	l = 143;
	T = P = H = 40755;

	for (;;) {
		H += 4*l + 1;
		++l;
		while(P < H) {
			P += 3*m + 1;
			++m;
		}
		while (T < H) {
			T += n + 1;
			++n;
		}
		if (H == P && H == T)
			break;
	}

	printf("Result: %d\n", H);

	return 0;
}
