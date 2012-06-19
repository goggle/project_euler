/*
 * Project Euler: Problem 44
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

struct node
{
	int *pent;
	struct node *next;
};
typedef struct node item;

int N = 0;
item *root;

//int getP(int n)
//{
//	static int d;
//	int i, ind;
//	static item *curr;
//	ind = n / 1000;
//	if(N == 0) {
//		d = 4;
//		root = (item*)malloc(sizeof(item));
//		root->next = NULL;
//		root->pent = (int*)malloc(1000*sizeof(int));
//		root->pent[0] = 1;
//		for (i = 1; i < 1000; ++i) {
//			root->pent[i] = root->pent[i-1] + d;
//			d += 3;
//		}
//		++N;
//		curr = root;
//	}
//	while (N <= ind) {
//		item *prev = curr;
//		curr->next = (item*)malloc(sizeof(item));
//		curr = curr->next;
//		//prev->next = curr;
//		curr->next = NULL;
//		curr->pent = (int*)malloc(1000*sizeof(int));
//		curr->pent[0] = prev->pent[1000-1];
//		d += 3;
//		for (i = 1; i < 1000; ++i) {
//			curr->pent[i] = curr->pent[i-1] + d;
//			d += 3;
//		}
//		++N;
//	}
//
//	curr = root;
//	n =  n - ind*1000 - ind;
//	while (ind > 0) {
//		curr = curr->next;
//		--ind;
//	}
//	return curr->pent[n];
//}

int getP(int n)
{
	return n*(3*n - 1)/2;
}

int isPentagonal(int p)
{
	int i;
	int n = (int)(0.5 + sqrt(0.25 + 6.0*p))/3.0;
	for (i = n-1; i <= n+1; ++i) {
		if (i >= 1 && p == getP(i))
			return TRUE;
	}
	return FALSE;
}

int main(void)
{
	int i, j, k, l;
	int pl, pj, pk;
	int p;
	int D;


	l = 3;
	pl = getP(l);	
	for(;;) {
		for (k = 1; k < l; ++k) {
			pk = getP(pk);
			//p = (pl > pk) ? pl - pk : pk - pl;
			D = abs(pl - pk);
			if (isPentagonal(D)) {
				if (isPentagonal(pl + pk)) {
					printf("%d\n", D);
				}
			}
		}
		++l;
		pl = getP(l);
				
	}

	//stop:
	//printf("pl = %d, pj = %d, pk = %d\n", pl, pj, pk);



	


	return 0;
}
