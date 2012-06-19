/*
 * Project Euler: Problem 5
 */
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

struct node
{
	int val;
	struct node *next;
};
typedef struct node item;

int N = 20;
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19};

int isPrime(int q)
{
	int n = sizeof(primes)/sizeof(int);
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		if (q == primes[i])
			return TRUE;
	}
	return FALSE;
}

int main(void)
{
	item *primefac[N-1];
	item *head, *curr, *prev;
	int i, j, n;
	int nprimes = sizeof(primes)/sizeof(int);
	int maxcoeff[nprimes];
	int count[nprimes];
	int lcm = 0;

	head = NULL;

	// Create List with integer factorizations
	for (i = 0; i < N-1; ++i)
	{
		head = NULL;
		prev = NULL;
		j = 0;
		n = i + 2;
		while (n != 1)
		{
			if (n % primes[j] == 0)
			{
				curr = (item*)malloc(sizeof(item));
				curr->val = primes[j];
				curr->next = NULL;
				if (head == NULL)
					head = curr;
				if (prev != NULL)
					prev->next = curr;
				prev = curr;
				n /= primes[j];
			}
			else
				++j;
		}
		primefac[i] = head;
		head = NULL;
		curr = NULL;
	}

	// Initialize arrays
	for (j = 0; j < nprimes; ++j)
	{
		count[j] = 0;
		maxcoeff[j] = 0;
	}

	// Count how many times the coefficients appear
	for (i = 0; i < N-1; ++i)
	{
		for (j = 0; j < nprimes; ++j)
		{
			count[j] = 0;
			head = primefac[i];
			while (head != NULL)
			{
				if (head->val == primes[j])
					++count[j];
				head = head->next;
			}
			if (count[j] > maxcoeff[j])
				maxcoeff[j] = count[j];
		}
	}

	// Calculate the least common multiple
	lcm = primes[0];
	--maxcoeff[0];
	for (j = 0; j < nprimes; ++j)
	{
		while (maxcoeff[j] > 0)
		{
			lcm *= primes[j];
			--maxcoeff[j];
		}
	}
	printf("Result: %d\n", lcm);

	return 0;
}
