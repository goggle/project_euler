/*
 * Project Euler: Problem 137
 */
#include <stdio.h>
#include <gmp.h>
	
int n = 15;

int main(void)
{
	int i;
	unsigned long int F[2*n + 1];
	mpz_t gn, x, y;
	mpz_init(gn);
	mpz_init(x);
	mpz_init(y);
	F[0] = 0;
	F[1] = 1;
	for (i = 2; i < 2*n+2; ++i) {
		F[i] = F[i-1] + F[i-2];
	}
	mpz_set_ui(x, F[2*n]);
	mpz_set_ui(y, F[2*n+1]);
	mpz_mul(gn, x, y);

	gmp_printf("Result: %Zd\n", gn);

	return 0;
}
