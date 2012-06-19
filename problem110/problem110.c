/*
 * Project Euler: Problem 110
 */
#include <stdio.h>
#include <gmp.h>


const long int N = 4*1e6;

long int getNumberOfSolutions(long int n)
{
	long int count = 0;
	long int n2 = n*n;
	int i;
	for (i = 1; i <= n2; ++i) {
		if (n2 % i == 0)
			++count;
	}
	if (count % 2 == 0)
		return count/2;
	return count/2+1;
}


int main(void)
{
	long int c;
	c = getNumberOfSolutions(25221);
	printf("Number of solutions: %d\n", c);


	return 0;
}
