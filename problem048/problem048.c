/*
 * Project Euler: Problem 48
 */

#include <stdio.h>

void add(int *d, int *d2, int *d3, int n)
{
	int i, u;
	int s;
	u = 0;
	for (i = n-1; i >= 0; --i) {
		s = d[i] + d2[i] + d3[i] + u;
		d[i] = s % 10;
		u = s / 10;
	}
}

void pot(int *d, int k, int n)
{
	int i, j, u;
	int u1, u2, u3;
	int k1, k2, k3;
	int s1, s2, s3;
	int d2[n];
	int d3[n];
	k1 = k % 10;
	k2 = (k/10)%10;
	k3 = k/100;

	for (i = 1; i < k; ++i) {
		d2[n-1] = 0;
		for (j = n-2; j >= 0; --j)
			d2[j] = d[j+1];
		d3[n-1] = d3[n-2] = 0;
		for (j = n-3; j >= 0; --j)
			d3[j] = d2[j+1];

		u1 = u2 = u3 = 0;
		for (j = n-1; j >= 0; --j) {
			s1 = k1 * d[j] + u1;
			s2 = k2 * d2[j] + u2;
			s3 = k3 * d3[j] + u3;
			d[j] = s1 % 10;
			d2[j] = s2 % 10;
			d3[j] = s3 % 10;
			u1 = s1 / 10;
			u2 = s2 / 10;
			u3 = s3 / 10;
		}
		add(d, d2, d3, n);
	}
}

int main(void)
{
	int i, j;
	int N = 10;
	int zeros[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int d[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int digits[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (i = 1; i <= 1000; ++i) {
		for (j = 0; j < N; ++j)
			d[j] = 0;
		d[N-1] = i%10;
		d[N-2] = (i/10)%10;
		d[N-3] = i/100;
		pot(d, i, N);
		add(digits, d, zeros, N);
	}

	for (i = 0; i < N; ++i)
		printf("%d", digits[i]);
	printf("\n");

	return 0;
}
