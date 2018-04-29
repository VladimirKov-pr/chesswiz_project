#include <stdio.h>
#include "layout.h"
#include "move.h"
#include "output.h"

void PawnMove ();
void PawnMoveWhite ();
void PawnMoveBlack ();

int main()
{	
	char con;
	char A[10][10];
	layout(A);
	output(A);
	char xx, xx1;
	int x, x1;
	int yy, yy1;
	int y, y1;
	printf("\n\n");
	while (1)
	{
		int flag = 0;
		do
		{
			flag = 0;
			printf("Print positions (ex: a2 a3)\n");
			scanf("%c %d %c %d", &xx, &yy, &xx1, &yy1);
			board1 (xx, yy, xx1, yy1);
			if (xx == 'a') {x = 1; flag++;}
			if (xx == 'b') {x = 2; flag++;}
			if (xx == 'c') {x = 3; flag++;}
			if (xx == 'd') {x = 4; flag++;}
			if (xx == 'e') {x = 5; flag++;}
			if (xx == 'f') {x = 6; flag++;}
			if (xx == 'g') {x = 7; flag++;}
			if (xx == 'h') {x = 8; flag++;}
			
			if (yy == 1) {y = 8; flag++;}
			if (yy == 2) {y = 7; flag++;}
			if (yy == 3) {y = 6; flag++;}
			if (yy == 4) {y = 5; flag++;}
			if (yy == 5) {y = 4; flag++;}
			if (yy == 6) {y = 3; flag++;}
			if (yy == 7) {y = 2; flag++;}
			if (yy == 8) {y = 1; flag++;}
			
			if (xx1 == 'a') {x1 = 1; flag++;}
			if (xx1 == 'b') {x1 = 2; flag++;}
			if (xx1 == 'c') {x1 = 3; flag++;}
			if (xx1 == 'd') {x1 = 4; flag++;}
			if (xx1 == 'e') {x1 = 5; flag++;}
			if (xx1 == 'f') {x1 = 6; flag++;}
			if (xx1 == 'g') {x1 = 7; flag++;}
			if (xx1 == 'h') {x1 = 8; flag++;}
			
			if (yy1 == 1) {y1 = 8; flag++;}
			if (yy1 == 2) {y1 = 7; flag++;}
			if (yy1 == 3) {y1 = 6; flag++;}
			if (yy1 == 4) {y1 = 5; flag++;}
			if (yy1 == 5) {y1 = 4; flag++;}
			if (yy1 == 6) {y1 = 3; flag++;}
			if (yy1 == 7) {y1 = 2; flag++;}
			if (yy1 == 8) {y1 = 1; flag++;}
		} while (flag != 4);
		printf("\n\n");	
		PawnMove(y, x, y1, x1, A);
		output(A);
		printf("\n\nExit? (print 'y')\n");
		scanf(" %c", &con);
		if (con == 'y')
		{
			return 0;
		}
	}
	return 0;
}

