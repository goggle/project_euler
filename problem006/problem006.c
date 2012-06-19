/*
 * Project Euler: Problem 6
 */
#include <stdio.h>

int main(void)
{
	int n = 100;
	int sum = (n+1)*n/2;

	double square_of_sum = sum*sum;
	double sum_of_square = 0;
	double diff;
	
	int i;
	for (i = 0; i < n; ++i)
	{
		sum_of_square += (i+1)*(i+1);
	}

	diff = square_of_sum - sum_of_square;

	printf("Result: %d\n", (int)diff);


	return 0;
}
