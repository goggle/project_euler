/*
 * Project Euler: Problem 26
 */
#include <stdio.h>
#include <stdlib.h>

struct node
{
	int r;
	int it;
	struct node *next;
};
typedef struct node item;


item* addElem(item *root, int r, int it)
{
	item* newElem = (item*)malloc(sizeof(item));
	newElem->r = r;
	newElem->it = it;
	newElem->next = root;
	return newElem;
}

int isElem(item *root, int r)
{
	item *curr = root;
	while (curr != NULL) {
		if (curr->r == r)
			return 1;
		curr = curr->next;
	}
	return 0;
}

int getIt(item *root, int r)
{
	item *curr = root;
	while (curr != NULL) {
		if (curr->r == r)
			return curr->it;
		curr = curr->next;
	}
	return 0;
}

void clearAndReinitialize(item **arr, int n)
{
	int i;
	item *curr, *next;
	for (i = 0; i < n; ++i) {
		next = curr = arr[i];
		if (curr != NULL) {
			do {
				next = curr->next;
				free(curr);
				curr = next;
			} while (next != NULL);
		}
		arr[i] = NULL;
	}
}

int main(void)
{
	int i;
	int d;
	int n, r;
	int it;
	int period;
	int longest_period = 0;
	int max_d;
	item* rest[10];
	for (i = 0; i < 10; ++i)
		rest[i] = NULL;

	for (d = 2; d < 1000; ++d) {
		clearAndReinitialize(rest, 10);
		i = 1;
		n = 10 / d;
		r = 10 % d;
		rest[n] = addElem(rest[n], r, i);
		for (;;) {
			n = 10 * r / d;
			r = 10 * r % d;
			if (isElem(rest[n], r)) {
				it = getIt(rest[n], r);
				period = i - it;
				if (period > longest_period) {
					longest_period = period;
					max_d = d;
				}
				break;
			}
			else {
				rest[n] = addElem(rest[n], r, i);
			}
			++i;
		}
	}
	
	printf("Result: %d\n", max_d);

	return 0;
}
