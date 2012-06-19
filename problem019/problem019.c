/*
 * Project Euler: Problem 19
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(void)
{
	int leap = FALSE;
	int y = 1900;
	int m = 1;
	int d = 1;
	int w = 1;
	int c = 0;
	
	while (y != 1901 || m != 1 || d != 1) {
		++d;
		w = ++w > 7 ? 1 : w;
		if (d > days[m]) {
			d = 1;
			++m;
			if (m > 12) {
				m = 1;
				++y;
			}
		}
	}

	do {
		if (d == 1 && w == 7)
			++c;
		++d;
		w = ++w > 7 ? 1 : w;
		if (d > days[m]) {
			d = 1;
			++m;
			if (m > 12) {
				m = 1;
				++y;
				if (y % 4 == 0) {
					if (y % 100 == 0) {
						if (y % 400 == 0)
							days[2] = 29;
						days[2] = 28;
					}
					days[2] = 29;
				}
				else
					days[2] = 28;
			}
		}
	} while (y != 2000 || m != 12 || d != 31);

	printf("Result: %d\n", c);

	return 0;
}
