/*
 * Project Euler: Problem 20
 */

#include <stdio.h>

int main(void)
{
	int N = 200; 
	int fac[N];
	int fac2[N];
	int i, j;
	int i1, i2;
	int s1, s2;
	int u1, u2;
	int u;
	int s;
	int sum ;

	for (i = 0; i < N; ++i) {
		fac[i] = 0;
		fac2[i] = 0;
	}

	// Use that 10!*100 = 362880000
	fac[195] = 8;
	fac[194] = 8;
	fac[193] = 2;
	fac[192] = 6;
	fac[191] = 3;

	for (i = 11; i < 100; ++i) {
		u = u1 = u2 = 0;
		for (j = 0; j < N-1; ++j) {
			fac2[j] = fac[j+1];
		}
		fac2[N-1] = 0;
		i1 = i%10;
		i2 = (i - i1)/10;
		for (j = N-1; j >= 0; --j) {
			s1 = fac[j]*i1 + u1;
			u1 = (s1 - (s1%10))/10;
			s1 = s1 % 10;
			fac[j] = s1;
			s2 = fac2[j]*i2 + u2;
			u2 = (s2 - (s2%10))/10;
			s2 = s2 % 10;
			fac2[j] = s2;
		}
		for (j = N-1; j >= 0; --j) {
			s = fac[j] + fac2[j] + u;
			if (s >= 10) {
				s -= 10;
				u = 1;
			}
			else {
				u = 0;
			}
			fac[j] = s;
		}
	}

	sum = 0;
	for (i = 0; i < N; ++i) {
		sum += fac[i];
	}
	printf("Result: %d\n", sum);

	return 0;
}
