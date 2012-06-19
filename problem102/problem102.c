/*
 * Project Euler: Problem 102
 *
 * Remark: This program prints out 229 as solution,
 * but it should be 228!
 */
#include <stdio.h>
#include <stdlib.h>

struct point_
{
	long x;
	long y;
};
typedef struct point_ point;

struct triangle_
{
	point a;
	point b;
	point c;
};
typedef struct triangle_ triangle;

struct node
{
	triangle t;
	struct node *next;
};
typedef struct node item;

item *root;


void addElem(long x1, long y1, long x2, long y2, long x3, long y3)
{
	if (root == NULL) {
		root = (item*)malloc(sizeof(item));
		root->t.a.x = x1;
		root->t.a.y = y1;
		root->t.b.x = x2;
		root->t.b.y = y2;
		root->t.c.x = x3;
		root->t.c.y = y3;
		root->next = NULL;
	}
	else {
		item *newElem;
		newElem = (item*)malloc(sizeof(item));
		newElem->t.a.x = x1;
		newElem->t.a.y = y1;
		newElem->t.b.x = x2;
		newElem->t.b.y = y2;
		newElem->t.c.x = x3;
		newElem->t.c.y = y3;
		newElem->next = root;
		root = newElem;
	}
}

void printList()
{
	item *curr = root;
	while (curr != NULL) {
		printf("Triangle: (%d, %d), (%d, %d), (%d, %d)\n", 
			curr->t.a.x, curr->t.a.y,
			curr->t.b.x, curr->t.b.y,
			curr->t.c.x, curr->t.c.y);
		curr = curr->next;
	}
}

inline int getNumber(char *number, int length)
{
	int i, j, k;
	int c;
	int sign;
	int pot;
	int n;

	c = 0;
	if (number[0] == '-') {
		sign = -1;
		i = j = 1;
	}
	else {
		sign = 1;
		i = j = 0;
	}
	while (number[i] != '\0') {
		++c;
		++i;
	}
	n = 0;
	pot = 1;
	k = j + c - 1;
	while (k >= j) {
		n += ((int)number[k] - 48) * pot;
		pot *= 10;
		--k;
	}
	n *= sign;
	return n;
}


void readData()
{
	int i, j, k, c;
	int coord[6] = {0, 0, 0, 0, 0, 0};
	FILE *fp;
	char string[80];
	char number[10];

	c = 0;
	fp = fopen("triangles.txt", "r");
	if (fp == NULL) {
		printf("Could not open triangles.txt for reading.\n");
		exit(0);
	}
	while (feof(fp) == 0) {
		for (i = 0; i < 80; ++i) {
			string[i] = '\0';
		}
		fscanf(fp, "%s", &string[0]);
		for (k = 0; k < 10; ++k) {
			number[k] = '\0';
		}
		j = 0;
		for (i = 0; i < 80; ++i) {
			if (string[i] != ',' && string[i] != '\0') {
				number[j] = string[i];
				++j;
			}
			else {
				/*
				int it = 0;
				while (number[it] != '\0') {
					printf("%d", number[it]);
					++it;
				}
				printf("\n");
				*/	
				coord[c] = getNumber(number, 10);
				++c;

				j = 0;
				for (k = 0; k < 10; ++k) {
					number[k] = '\0';
				}
				if (string[i] == '\0') {
					c = 0;
					break;
				}
			}
		}
		addElem(coord[0], coord[1], coord[2], coord[3], coord[4], coord[5]);
	}
	fclose(fp);
}

int originIsInTriangle(triangle t)
{
	double l1, l2, l3;
	long detT = (t.a.x - t.c.x) * (t.b.y - t.c.y) 
		- (t.b.x - t.c.x) * (t.a.y - t.c.y);
	l1 = ((double) ((t.b.y - t.c.y)*(-t.c.x) + (t.c.x - t.b.x)*(-t.c.y)))/detT;
	l2 = ((double) ((t.c.y - t.a.y)*(-t.c.x) + (t.a.x - t.c.x)*(-t.c.y)))/detT;
	l3 = 1 - l1 - l2;
	if (l1 > 0 && l1 < 1 && l2 > 0 && l2 < 1 && l3 > 0 && l3 < 1)
		return 1;
	return 0;
}



int main(void)
{
	unsigned int count = 0;
	item *curr;

	readData();

	curr = root;
	while (curr != NULL) {
		if (curr->t.a.x == curr->t.b.x && curr->t.a.y == curr->t.b.y)
			curr = curr->next;
		if (curr->t.b.x == curr->t.c.x && curr->t.b.y == curr->t.c.y)
			curr = curr->next;
		if (curr->t.a.x == curr->t.c.x && curr->t.a.y == curr->t.c.y)
			curr = curr->next;
		if (originIsInTriangle(curr->t))
			++count;
		curr = curr->next;
	}
	
	printf("Result: %d\n", count);

	return 0;
}
