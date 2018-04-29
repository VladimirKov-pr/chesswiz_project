#include <stdio.h>

void output(char (*A)[10])
{
	int i, j;
	for (i = 0; i <= 9; i++)
	{
		printf("\n\n");
		for (j = 0; j <= 9; j++)
		printf(" %c ",A[i][j]);
	}
}
