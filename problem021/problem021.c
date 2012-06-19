/*
 * Project Euler: Problem 21
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

int isElem(item *root, int val)
{
	item *curr = root;
	while (curr != NULL) {
		if (curr->val == val)
			return TRUE;
	}
	return FALSE;
}

item* addElem(item* root, int val)
{
	item *newElem;
	newElem = (item*)malloc(sizeof(item));
	newElem->val = val;
	newElem->next = root;
	return newElem;
}

void printList(item *root)
{
	item *curr = root;
	while (curr != NULL) {
		printf("%d\n", curr->val);
		curr = curr->next;
	}
}

item* copyList(item *copy)
{
	item *curr;
	item *next;
	item *root;
	curr = (item*)malloc(sizeof(item));
	curr->val = copy->val;
	curr->next = NULL;
	root = curr;
	next = copy->next;
	while (next != NULL) {
		item *newItem = (item*)malloc(sizeof(item));
		newItem->val = next->val;
		newItem->next = NULL;
		curr->next = newItem;
		curr = curr->next;
		next = next->next;
	}
	return root;
}

int getSum(item *root)
{
	item *curr = root;
	int s = 0;
	while (curr != NULL) {
		s += curr->val;
		curr = curr->next;
	}
	return s;
}


int main(void)
{
	const int N = 10000;
	item* divisors[N];
	int sum[N];
	int i, j, k;
	int d, s;
	for (i = 0; i < N; ++i)
		divisors[i] = NULL;
		sum[i] = 0;
	for (i = 1; i < N; ++i) {
		if (divisors[i] == NULL) {
			divisors[i] = (item*)malloc(sizeof(item));
			divisors[i]->val = 1;
			divisors[i]->next = NULL;
			for (j = 2; j <= i/2; ++j) {
				if (i % j == 0) {
					divisors[i] = addElem(divisors[i], j);
				}
			}
		}
		//if (i == 1)
		//	continue;
		//for (j = 2; ; ++j) {
		//	k = i*j;
		//	if (k >= N)
		//		break;
		//	if (divisors[j] != NULL && divisors[k] == NULL) {
		//		printf("Here: i = %d, j = %d\n", i, j);
		//		printList(divisors[j]);
		//		divisors[k] = copyList(divisors[i]);
		//		item* curr = divisors[j];
		//		while (curr != NULL) {
		//			//if(isElem(divisors[k], curr->val) == FALSE)
		//				divisors[k] = addElem(divisors[k], curr->val);
		//			curr = curr->next;
		//		}
		//		divisors[k] = addElem(divisors[k], i);
		//		divisors[k] = addElem(divisors[k], j);
		//	}
		//}
	}

	for (i = 1; i < N; ++i) {
		sum[i] = getSum(divisors[i]);
	}

	s = 0;
	for (i = 1; i < N; ++i) {
		d = sum[i];
		if (d < N && d !=i && sum[d] == i)
			s += d;
	}
	printf("Result: %d\n", s);

	return 0;
}
