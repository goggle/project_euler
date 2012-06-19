/*
 * Project Euler: Problem 36
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

const int N = 1e6;
const int arrsize = 20;

int* decToBin(int n)
{
	int* bitVector = (int*)malloc(arrsize*sizeof(int));
	int i;
	for (i = 0; i < arrsize; ++i) {
		bitVector[i] = 0;
	}
	i = 0;
	while(n > 0) {
		if(n % 2 == 0) 
			bitVector[i] = 0;
		else
			bitVector[i] = 1;
		n /= 2;
		++i;
	}
	return bitVector;
}

int isPalindrom(int* bin)
{
	int i = arrsize-1;
	int j = 0;
	while (bin[i] == 0)
		--i;
	while (i > j) {
		if (bin[i] != bin[j])
			return FALSE;
		--i;
		++j;
	}
	return TRUE;
}
	

int main(void)
{
	int sum = 0;
	int* bin;
	int i, j, k;

	int n;
	for (i = 1; i <= 9; ++i) {
		n = i;
		bin = decToBin(n);
		if (isPalindrom(bin)) {
			sum += n;
		}
		free(bin);
		n = i + i*10;
		bin = decToBin(n);
		if (isPalindrom(bin))
			sum += n;
		free(bin);
	}

	for (i = 1; i <= 9; ++i) {
		for (j = 0; j <= 9; ++j) {
			n = i + 10*j + 100*i;
			bin = decToBin(n);
			if (isPalindrom(bin))
				sum += n;
			free(bin);
			
			n = i + 10*j + 100*j + 1000*i;
			bin = decToBin(n);
			if (isPalindrom(bin))
				sum += n;
			free(bin);
		}
	}

	for (i = 1; i <= 9; ++i) {
		for (j = 0; j <= 9; ++j) {
			for (k = 0; k <= 9; ++k) {
				n = i + 10*j + 100*k + 1000*j + 10000*i;
				bin = decToBin(n);
				if (isPalindrom(bin))
					sum += n;
				free(bin);

				n = i + 10*j + 100*k + 1000*k + 10000*j + 100000*i;
				bin = decToBin(n);
				if (isPalindrom(bin))
					sum += n;
			}
		}
	}

	printf("Result: %d\n", sum);

	return 0;
}
