#ifndef UHEADER_H_
#define UHEADER_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void layout(char (*A)[10]);
void board1 (int xx, int yy, int xx1, int yy1);
_Bool move (int y, int x, int y1, int x1, char (*A)[10]);
void output(char (*A)[10]);


#endif
