/*
 * Project Euler: Problem 205
 */
#include <stdio.h>

int main(void)
{
    int poss_pyr[36] = {0};
    int poss_cub[36] = {0};
    int i1,i2,i3,i4,i5,i6,i7,i8,i9;
    int i, j;
    double c;
    double total = 12230590464;
    double prob;

    for (i1 = 1; i1 <= 4; ++i1)
    for (i2 = 1; i2 <= 4; ++i2)
    for (i3 = 1; i3 <= 4; ++i3)
    for (i4 = 1; i4 <= 4; ++i4)
    for (i5 = 1; i5 <= 4; ++i5)
    for (i6 = 1; i6 <= 4; ++i6)
    for (i7 = 1; i7 <= 4; ++i7)
    for (i8 = 1; i8 <= 4; ++i8)
    for (i9 = 1; i9 <= 4; ++i9)
        poss_pyr[i1+i2+i3+i4+i5+i6+i7+i8+i9]++;

    for (i1 = 1; i1 <= 6; ++i1)
    for (i2 = 1; i2 <= 6; ++i2)
    for (i3 = 1; i3 <= 6; ++i3)
    for (i4 = 1; i4 <= 6; ++i4)
    for (i5 = 1; i5 <= 6; ++i5)
    for (i6 = 1; i6 <= 6; ++i6)
        poss_cub[i1+i2+i3+i4+i5+i6]++;

    c = 0;
    for (i = 1; i < 37; ++i) {
        for (j = 1; j < i; ++j) {
            c += poss_cub[j] * poss_pyr[i];
        }
    }
    printf("%.8f\n", (double)c/total);

    return 0;
}

