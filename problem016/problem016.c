/*
 * Project Euler: Problem 16
 */

#include <stdio.h>

int main(void)
{
	const int N = 1000;
	const int arrsize = 400;
	int pot[arrsize];
	int i, j;
	int s = 0;
	int u = 0;
	int sum = 0;
	for (i = 0; i < arrsize; ++i)
		pot[i] = 0;
	pot[arrsize-1] = 2;
	
	for (i = 0; i < N-1; ++i) {
		for (j = arrsize-1; j >= 0; --j) {
			s = pot[j]*2;
			if (s >= 10) {
				pot[j] = (s-10) + u;
				u = 1;
			}
			else {
				pot[j] = s + u;
				u = 0;
			}
		}
	}

	for (i = 0; i < arrsize; ++i)
		s += pot[i];
	
	printf("Result: %d\n", s);

	return 0;
}
