/*
 * Project Euler: Problem 2
 */
#include <stdio.h>

int main(void)
{
	int f1 = 1;
	int f2 = 2;
	int fn = f1 + f2;
	int N = 4*1e6;
	int i = 0;
	int sum = f2;
	int tmp;

	while (fn < N)
	{
		tmp = fn + f2;
		f1 = f2;
		f2 = fn;
		fn = tmp;
		if (fn % 2 == 0 && fn < N)
			sum += fn;
	}

	printf("Result: %d\n", sum);

	return 0;
}
