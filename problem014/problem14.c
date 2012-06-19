/*
 * Project Euler: Problem 14
 */

#include <stdio.h>

int main(void)
{
	int N = 1e6;
	int count = 0;
	int start = 1;
	int c = 0;
	unsigned int n;
	int i;
	
	int lookUp[N];
	for (i = 0; i < N; ++i)
		lookUp[i] = 0;

	for (i = 2; i < N; ++i) {
		c = 0;
		n = i;
		while (n != 1) {
			if (n < N && lookUp[n] != 0) {
				c += lookUp[n];
				break;
			}
			else if (n % 2 == 0)
				n = n/2;
			else
				n = 3*n+1;
			++c;
		}
		if (c >= count) {
			count = c;
			start = i;
		}
		lookUp[i] = c;
	}
	printf("Result: %d\n", start);

	return 0;
}
