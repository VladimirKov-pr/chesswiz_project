#include <stdio.h>
#include <stdlib.h>

void board (char (*A)[10])
{
	FILE *ff;
	ff = fopen("Board.txt","a");
	int i,j;
	for (i = 0; i <= 9; i++)
	{
		fprintf(ff, "\n");
		for (j = 0; j <= 9; j++)
		fprintf(ff, " %c ", A[i][j]);
	}
	fclose(ff);
}

void board1 (int xx, int yy, int xx1, int yy1)
{
	FILE *ff;
	ff = fopen("Board.txt","a");
	fprintf(ff, "\n");
	fprintf(ff, " %c%d %c%d ", xx, yy, xx1, yy1);
	fprintf(ff, "\n");
	fclose(ff);
}

void PawnMoveWhite (int y, int x, int y1, int x1, char (*A)[10])
{
	if (A[y][x] == 'p')
	{
		if (A[y1][x1] == ' ' && x == x1 && abs(y1-y) <= 2)
		{
			printf("Possible move");
			A[y1][x1] = A[y][x];
			A[y][x] = ' ';
		}
	}
}

void PawnMoveBlack (int y, int x, int y1, int x1, char (*A)[10])
{
	if (A[y][x] == 'P')
	{
		if (A[y1][x1] == ' ' && x == x1 && abs(y1-y) <= 2)
		{
			printf("Possible move");
			A[y1][x1] = A[y][x];
			A[y][x] = ' ';
		}
	}
}

void PawnMove (int y, int x, int y1, int x1, char (*A)[10])
{
	if (A[y][x] == 'p')
	{
		PawnMoveWhite(y, x, y1, x1, A);
		board (A);

	}
	if (A[y][x] == 'P')
	{
		PawnMoveBlack(y, x, y1, x1, A);	
		board (A);
	}
}
