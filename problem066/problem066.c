/*
 * Project Euler: Problem 66
 */
#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

struct node
{
	unsigned long int x;
	mpz_t square;
	struct node *next;
};
typedef struct node item;

int N = 1000;
item *root;

void initList(unsigned long int n)
{
	unsigned long int i = 1;
	mpz_t i2;
	mpz_t x2;
	mpz_init(i2);
	mpz_init(x2);
	item *curr;
	root = (item*)malloc(sizeof(item));
	root->x = 1;
	mpz_init(root->square);
	mpz_set_ui(root->square, i);
	root->next = NULL;
	curr = root;
	for (i = 2; i <= n; ++i) {
		curr->next = (item*)malloc(sizeof(item));
		curr = curr->next;
		curr->x = i;
		mpz_set_ui(i2, i);
		mpz_mul(x2, i2, i2);
		mpz_init(curr->square);
		mpz_set(curr->square, x2);
		//curr->square = i*i;
		curr->next = NULL;
	}
}


void printList()
{
	item *curr = root;
	while (curr != NULL) {
		gmp_printf("n = %d, square = %Zd\n", curr->x, curr->square);
		curr = curr->next;
	}
}


int findMinimalX(unsigned long int d)
{
	//unsigned long int y = 1;
	//int x_square;
	mpz_t y;
	mpz_t y2;
	mpz_t x_square;
	mpz_init(y);
	mpz_init(y2);
	mpz_init(x_square);
	mpz_set_ui(y, 1);

	item *curr;
	for (;;) {
		curr = root;
		mpz_mul(y2, y, y);
		mpz_mul_ui(x_square, y2, d);
		mpz_add_ui(x_square, x_square, 1);
		//x_square = d*y*y + 1;
		//printf("y = %d, x2 = %d curr->square = %d\n", y, x_square, curr->square);
		//while (x_square >= curr->square) {
		while (mpz_cmp(x_square, curr->square) >= 0) {
			//if (x_square == curr->square)
			if (mpz_cmp(x_square, curr->square) == 0)
				return curr->x;
			if (curr->next == NULL)
				return -1;
			curr = curr->next;
		}
		//++y;
		mpz_add_ui(y, y, 1);
	}
	return 0;
}

int isSquare(mpz_t sq)
{
	item *curr = root;
	while (mpz_cmp(sq, curr->square) >= 0) {
		if (mpz_cmp(sq, curr->square) == 0)
			return 1;
		if (curr->next == NULL)
			return -1;
		curr = curr->next;
	}
	return 0;
}

int getRoot(mpz_t sq)
{
	item *curr = root;
	while (mpz_cmp(sq, curr->square) >= 0) {
		if (mpz_cmp(sq, curr->square) == 0)
			return curr->x;
		if (curr->next == NULL)
			return -1;
		curr = curr->next;
	}
	return -1;
}

int findMinimal(unsigned int d)
{
	unsigned int x, y;
	mpz_t x2min1;
	mpz_t x2;
	unsigned int c = 1;
	mpz_init(x2min1);
	mpz_init(x2);
	for (;;) {
		mpz_set_ui(x2min1, c);
		mpz_mul_ui(x2min1, x2min1, c);
		mpz_mul_ui(x2min1, x2min1, d);
		mpz_set(x2, x2min1);
		mpz_add_ui(x2, x2, 1);
		if (isSquare(x2) == 1) {
			return getRoot(x2);
		}
		++c;
	}
	return 0;

}




int main(void)
{
	int i, j;
	int D[N+1];
//	int x, y, d;
//	int s;
//	int xmax, dsol;
//	xmax = 0;

	for (i = 0; i < N+1; ++i)
		D[i] = -1;
	D[0] = D[1] = 0;
	for (i = 2; i < N+1; ++i) {
		j = i*i;
		if (j < N+1)
			D[j] = 0;
		if (D[i] == 0)
			continue;
		D[i] = 1;
	}

	initList(1000000);
	//printList();
	//int x = findMinimalX(133);
	//printf("x = %d\n", x);




//	for (d = 1; d < N+1; ++d) {
//		if (D[d] == 0)
//			continue;
//		printf("d = %d\n", d);
//		x = 1;
//		y = 1;
//		for (;;) {
//			s = x*x - d*y*y;
//			if (s == 1) { /* solution found */
//				if (x > xmax) {
//					xmax = x;
//					dsol = d;
//				}
//				break;
//			}
//			else if (s < 1) { /* there is no solution with this x */
//				y = 1;
//				++x;
//			}
//			else {
//				++y;
//			}
//		}
//	}
//
//	printf("Result: %d\n", dsol);
	
	int x = findMinimal(877);
	printf("x = %d\n", x);


	return 0;
}
