/*
 * Project Euler: Problem 10
 * 
 */
#include <stdio.h>
#include <math.h>
#include <gmp.h>

unsigned long int N = 2e6;

int isPrime(unsigned long int p)
{
	int i = 2;
	int sq = (int)sqrt(p);
	if (p % i == 0 && p != 2)
		return 0;
	++i;
	while (i <= sq) {
		if (p % i == 0)
			return 0;
		i += 2;
	}
	return 1;
}

int main(void)
{
	unsigned long int i;
	mpz_t sum;
	mpz_init(sum);
	mpz_set_ui(sum, 0);

	for (i = 2; i < N; ++i) {
		/*
		if (i % 10000 == 0)
			gmp_printf("i = %d, sum = %Zd\n", i, sum);
		*/
		if (isPrime(i))
			mpz_add_ui(sum, sum, i);
	}

	gmp_printf("Result: %Zd\n", sum);

	return 0;
}
