#include "uheader.h"

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

bool move(int y, int x, int y1, int x1, char (*A)[10])
{
	if (A[y][x] == 'p') //white pawns
	{
		if (A[y1][x1] == ' ' && x == x1 && abs(y1-y) <= 2)
		{
			A[y1][x1] = A[y][x];
			A[y][x] = ' ';
			board (A);
			return true;
		}
		if (A[y1][x1] != ' ' && A[y1][x1] >= 65 && A[y1][x1] <= 90 && ((y-1 == y1 && x-1 == x1) || (y-1 == y1 && x+1 == x1)))
		{
			A[y1][x1] = A[y][x];
			A[y][x] = ' ';
			board (A);
			return true;
		}
		return false;
	}
	if (A[y][x] == 'P') //black pawns
	{
		if (A[y1][x1] == ' ' && x == x1 && abs(y1-y) <= 2)
		{
			A[y1][x1] = A[y][x];
			A[y][x] = ' ';
			board (A);
			return true;
		}
		if (A[y1][x1] != ' ' && A[y1][x1] >= 97 && A[y1][x1] <= 122 && ((y+1 == y1 && x-1 == x1) || (y+1 == y1 && x+1 == x1)))
		{
			A[y1][x1] = A[y][x];
			A[y][x] = ' ';
			board (A);
			return true;
		}
		return false;
	}
	if (A[y][x] == 'r') //white rooks
	{
		if (A[y1][x1] == ' ' && (x == x1 || y == y1))
		{
			A[y1][x1] = A[y][x];
			A[y][x] = ' ';
			board (A);
			return true;
		}
		if (A[y1][x1] != ' ' && A[y1][x1] >= 65 && A[y1][x1] <= 90 && (x == x1 || y == y1))
		{
			A[y1][x1] = A[y][x];
			A[y][x] = ' ';
			board (A);
			return true;
		}
		return false;
	}
	if (A[y][x] == 'R') //black rooks
	{
		if (A[y1][x1] == ' ' && (x == x1 || y == y1))
		{
			A[y1][x1] = A[y][x];
			A[y][x] = ' ';
			board (A);
			return true;
		}
		if (A[y1][x1] != ' ' && A[y1][x1] >= 97 && A[y1][x1] <= 122 && (x == x1 || y == y1))
		{
			A[y1][x1] = A[y][x];
			A[y][x] = ' ';
			board (A);
			return true;
		}
		return false;
	}
	if (A[y][x] == 'n') // while knight (horse)
	{
		if (A[y1][x1] == ' ' && (pow(x1-x, 2) + pow (y1-y, 2)) == 5)
		{
			A[y1][x1] = A[y][x];
			A[y][x] = ' ';
			board (A);
			return true;
		}
		if (A[y1][x1] != ' ' && A[y1][x1] >= 65 && A[y1][x1] <= 90 && (pow(x1-x, 2) + pow(y1-y, 2)) == 5)
		{
			A[y1][x1] = A[y][x];
			A[y][x] = ' ';
			board (A);
			return true;
		}
		return false;
	}
	if (A[y][x] == 'N') // black knight (horse)
	{
		if (A[y1][x1] == ' ' && (pow(x1-x, 2) + pow(y1-y, 2)) == 5)
		{
			A[y1][x1] = A[y][x];
			A[y][x] = ' ';
			board (A);
			return true;
		}
		if (A[y1][x1] != ' ' && A[y1][x1] >= 97 && A[y1][x1] <= 122 && (pow(x1-x, 2) + pow(y1-y, 2)) == 5)
		{
			A[y1][x1] = A[y][x];
			A[y][x] = ' ';
			board (A);
			return true;
		}
		return false;
	}
	if (A[y][x] == 'b') // bishop white (elephant)
	{
		if (A[y1][x1] == ' ' && abs(y1-y) == abs(x1-x))
		{
			A[y1][x1] = A[y][x];
			A[y][x] = ' ';
			board (A);
			return true;
		}
		if (A[y1][x1] != ' ' && A[y1][x1] >= 65 && A[y1][x1] <= 90 && abs(y1-y) == abs(x1-x))
		{
			A[y1][x1] = A[y][x];
			A[y][x] = ' ';
			board (A);
			return true;
		}
		return false;
	}
	if (A[y][x] == 'B') // bishop black (elephant)
	{
		if (A[y1][x1] == ' ' && abs(y1-y) == abs(x1-x))
		{
			A[y1][x1] = A[y][x];
			A[y][x] = ' ';
			board (A);
			return true;
		}
		if (A[y1][x1] != ' ' && A[y1][x1] >= 97 && A[y1][x1] <= 122 && abs(y1-y) == abs(x1-x))
		{
			A[y1][x1] = A[y][x];
			A[y][x] = ' ';
			board (A);
			return true;
		}
		return false;
	}
	if (A[y][x] == 'q') // white queen (ferz')
	{
		if (A[y1][x1] == ' ' && (x == x1 || y == y1 || (abs(y1-y) == abs(x1-x))))
		{
			A[y1][x1] = A[y][x];
			A[y][x] = ' ';
			board (A);
			return true;
		}
		if (A[y1][x1] != ' ' && (x == x1 || y == y1 || (abs(y1-y) == abs(x1-x))) && A[y1][x1] >= 65 && A[y1][x1] <= 90)
		{
			A[y1][x1] = A[y][x];
			A[y][x] = ' ';
			board (A);
			return true;
		}
		return false;
	}
	if (A[y][x] == 'Q') // black queen (ferz')
	{
		if (A[y1][x1] == ' ' && (x == x1 || y == y1 || (abs(y1-y) == abs(x1-x))))
		{
			A[y1][x1] = A[y][x];
			A[y][x] = ' ';
			board (A);
			return true;
		}
		if (A[y1][x1] != ' ' && (x == x1 || y == y1 || (abs(y1-y) == abs(x1-x))) && A[y1][x1] >= 97 && A[y1][x1] <= 122)
		{
			A[y1][x1] = A[y][x];
			A[y][x] = ' ';
			board (A);
			return true;
		}
		return false;
	}
	if (A[y][x] == 'k') // white king
	{
		if (A[y1][x1] == ' ' && (abs(y1-y) == 1 || abs(x1-x) == 1))
		{
			A[y1][x1] = A[y][x];
			A[y][x] = ' ';
			board (A);
			return true;
		}
		if (A[y1][x1] != ' ' && (abs(y1-y) == 1 || abs(x1-x) == 1) && A[y1][x1] >= 65 && A[y1][x1] <= 90)
		{
			A[y1][x1] = A[y][x];
			A[y][x] = ' ';
			board (A);
			return true;
		}
		return false;
	}
	if (A[y][x] == 'K') // black king
	{
		if (A[y1][x1] == ' ' && (abs(y1-y) == 1 || abs(x1-x) == 1))
		{
			A[y1][x1] = A[y][x];
			A[y][x] = ' ';
			board (A);
			return true;
		}
		if (A[y1][x1] != ' ' && (abs(y1-y) == 1 || abs(x1-x) == 1) && A[y1][x1] >= 97 && A[y1][x1] <= 122)
		{
			A[y1][x1] = A[y][x];
			A[y][x] = ' ';
			board (A);
			return true;
		}
		return false;
	}
	return false;
}
