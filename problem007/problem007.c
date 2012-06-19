/*
 * Project Euler: Problem 7
 */

#include <stdio.h>
#define TRUE 1
#define FALSE 0

int main(void)
{
	const int n = 500000;
	const int np = 10001;
	int primes[np];
	int list[n];
	int i, j, k;

	for (i = 0; i < n; ++i)
	{
		list[i] = FALSE;
	}
	list[0] = list[1] = TRUE;

	k = 0;
	for (i = 2; i < n; ++i)
	{
		if (k == np)
			break;
		if (list[i] == FALSE)
		{
			primes[k] = i;
			++k;
			printf("%d, p = %d\n",k, i);
		}
		for (j = i*i; j < n; j += i)
		{
			list[j] = TRUE;
		}
	}


	




	return 0;
}
