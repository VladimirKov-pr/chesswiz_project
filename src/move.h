#ifndef MOVE_H_
#define MOVE_H_

void board1 (int xx, int yy, int xx1, int yy1);
void PawnMove (int y, int x, int y1, int x1, char (*A)[10]);
void PawnMoveWhite (int y, int x, int y1, int x1, char (*A)[10]);
void PawnMoveBlack (int y, int x, int y1, int x1, char (*A)[10]);

#endif
