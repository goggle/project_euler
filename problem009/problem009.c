/*
 * Project Euler: Problem 9
 */

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int a, b, c;
	struct node *next;
};
typedef struct node item;

int main(void)
{
	item *head, *curr, *prev;
	head = NULL;
	prev = NULL;
	int a, b, c;
	for (a = 0; a <= 333; ++a) {
		for (b = a+1; b <= 500; ++b) {
			c = 1000 - a - b;
			if (c > b) {
				curr = (item*)malloc(sizeof(item));
				curr->a = a;
				curr->b = b;
				curr->c = c;
				curr->next = NULL;
				if (head == NULL) {
					head = curr;
					prev = curr;
				}
				else {
					prev->next = curr;
					prev = curr;
				}
			}
		}
	}

	curr = head;
	while (curr != NULL) {
		if (curr->a*curr->a + curr->b*curr->b == curr->c*curr->c) {
			printf ("a = %d, b = %d, c = %d\n", curr->a, curr->b, curr->c);
			printf ("Result: %d\n", curr->a*curr->b*curr->c);
			break;
		}
		curr = curr->next;
	}

	return 0;
}


