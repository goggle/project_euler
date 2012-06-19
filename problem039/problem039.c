/*
 * Project Euler: Problem 39
 */
#include <stdio.h>
#include <math.h>

int N = 1000;

int isSquare(unsigned int sq)
{
	int s = (int)sqrt(sq);
	if (s*s == sq)
		return 1;
	return 0;
}


int main(void)
{
	unsigned int p, a, b, c;
	unsigned int a2, b2, c2;
	unsigned int nsol, nsol_max, p_max;
	nsol = nsol_max = p_max = 0;
	for (p = 3; p <= N; ++p) {
		nsol = 0;
		c = p-2;
		c2 = c * c;
		while (c > 0) {
			a = 1;
			a2 = a * a;
			b2 = c2 - a2;
			b = (int)sqrt(b2);
			while (a <= b) {
				a2 = a * a;
				b2 = c2 - a2;
				b = (int)sqrt(b2);
				if (isSquare(b2) && p == a + b + c)
					++nsol;
				++a;
			}
			--c;
			c2 = c * c;
		}
		if (nsol > nsol_max) {
			nsol_max = nsol;
			p_max = p;
		}
	}

	printf("Result: %d\n", p_max);

	return 0;
}
