/*
 * Project Euler: Problem 1
*/
#include <stdio.h>

int main(void)
{
	int N = 999;
	int n3 = 999/3;
	int n5 = 999/5;
	int n15 = 999/15;
	int n = n3 + n5;
	
	int mult3[n3];
	int mult5[n5];

	int i = 0;

	int sum = 0;
	for (i = 0; i < n3; ++i)
		sum += (i+1)*3;
	for (i = 0; i < n5; ++i)
		sum += (i+1)*5;
	for (i = 0; i < n15; ++i)
		sum -= (i+1)*15;
	
	printf("Result: %d\n", sum);

	return 0;
}
