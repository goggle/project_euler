/*
 * Project Euler: Problem 11
 */
#include <stdio.h>
#include <stdlib.h>

int data[20][20];

int readData()
{
	FILE *fp;
	char c, d, e;
	int i, j;
	i = 0;
	fp = fopen("data.txt", "r");
	if (fp == NULL) {
		puts("Cannot open file.\n");
		return 1;
	}
	for (i = 0; i < 20; ++i) {
		for (j = 0; j < 20; ++j) {
			c = fgetc(fp);
			d = fgetc(fp);
			e = fgetc(fp);
			data[i][j] = ((int)c - 48)*10 + (int)d - 48;
		}
	}
	return 0;
}

inline int isValid(int i1, int j1, int i2, int j2,
	int i3, int j3, int i4, int j4)
{
	if (i1 >= 0 && i1 < 20 && i2 >= 0 && i2 < 20 &&
		i3 >= 0 && i3 < 20 && i4 >= 0 && i4 < 20 &&
		j1 >= 0 && j1 < 20 && j2 >= 0 && j2 < 20 &&
		j3 >= 0 && j3 < 20 && j4 >= 0 && j4 < 20)
		return 1;
	return 0;
}



int main(void)
{
	int i, j;
	int i1, i2, i3, i4;
	int j1, j2, j3, j4;
	int max = 0;
	int m;
	int d = readData();

	for (i = 0; i < 20; ++i) {
		for (j = 0; j < 20; ++j) {
			i1 = i;
			j1 = j;
			i2 = i + 1;
			i3 = i + 2;
			i4 = i + 3;
			j2 = j3 = j4 = j;
			if (isValid(i1, j1, i2, j2, i3, j3, i4, j4)) {
				m = data[i1][j1] * data[i2][j2] * data[i3][j3] * data[i4][j4];
				if (m > max)
					max = m;
			}
			i2 = i3 = i4 = i;
			j2 = j + 1;
			j3 = j + 2;
			j4 = j + 3;
			if (isValid(i1, j1, i2, j2, i3, j3, i4, j4)) {
				m = data[i1][j1] * data[i2][j2] * data[i3][j3] * data[i4][j4];
				if (m > max)
					max = m;
			}
			i2 = i+1;
			i3 = i+2;
			i4 = i+3;
			if (isValid(i1, j1, i2, j2, i3, j3, i4, j4)) {
				m = data[i1][j1] * data[i2][j2] * data[i3][j3] * data[i4][j4];
				if (m > max)
					max = m;
			}
			i2 = i + 1;
			i3 = i + 2;
			i4 = i + 3;
			j2 = j - 1;
			j3 = j - 2;
			j4 = j - 3;
			if (isValid(i1, j1, i2, j2, i3, j3, i4, j4)) {
				m = data[i1][j1] * data[i2][j2] * data[i3][j3] * data[i4][j4];
				if (m > max)
					max = m;
			}
		}
	}
	
	printf("Result: %d\n", max);

	return 0;
}

