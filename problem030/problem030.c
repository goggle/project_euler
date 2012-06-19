/*
 * Project Euler: Problem 30
 */
#include <stdio.h>
#define POW5(x) ((x)*(x)*(x)*(x)*(x))

 int main(void)
 {
	 int d1, d2, d3, d4, d5, d6;
	 int i;
	 int N = 500000;
	 int sum = 0;
	 for (i = 2; i < N; ++i) {
		 d1 = i % 10;
		 d2 = (i / 10) % 10;
		 d3 = (i / 100) % 10;
		 d4 = (i / 1000) % 10;
		 d5 = (i / 10000) % 10;
		 d6 = (i / 100000);
		 if (POW5(d1) + POW5(d2) + POW5(d3) + POW5(d4) + POW5(d5) + POW5(d6) == i) {
			 sum += i;
		 }
	 }
	 printf("Result: %d\n", sum);

	 return 0;
 }
