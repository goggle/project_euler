/*
 * Project Euler: Problem 29
 */
#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

#define TRUE 1
#define FALSE 0 

struct node
{
	mpz_t val;
	struct node *next;
};
typedef struct node item;

int count = 0;
item *root = NULL;

void addElem(mpz_t value)
{
	if (root == NULL) {
		root = (item*)malloc(sizeof(item));
		mpz_init(root->val);
		mpz_set(root->val, value);
		root->next = NULL;
	}
	else {
		item *curr;
		curr = (item*)malloc(sizeof(item));
		mpz_init(curr->val);
		mpz_set(curr->val, value);
		curr->next = root;
		root = curr;
	}
	++count;
}

int isElem(mpz_t value)
{
	item *curr = root;
	while (curr != NULL) {
		if (mpz_cmp(curr->val, value) == 0)
			return TRUE;
		curr = curr->next;
	}
	return FALSE;
}


int main(void)
{
	unsigned long int a, b;
	mpz_t s;
	mpz_init(s);
	for (a = 2; a <= 100; ++a) {
		for (b = 2; b <= 100; ++b) {
			mpz_ui_pow_ui(s, a, b);
			if (!isElem(s))
				addElem(s);
		}
	}
	printf("Result: %d\n", count);

	return 0;
}
