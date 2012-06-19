#include <stdio.h>

int main(void)
{
	int i;
	for (i = 1; i < 1000; ++i)
		printf("%d^%d+", i, i);
	printf("1000^1000\n");
	return 0;
}
