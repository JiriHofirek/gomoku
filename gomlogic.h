#include <stdlib.h>

#define EMPTY 0
#define BLACK 1
#define WHITE 2
// number of stones in the row whitch is winning
#define WINNING 5



/* 
 * creats 1D array whitch represtns 2D array of game board
 * sets all cells in the array EMPTY
*/
int *alloc_board(int size);

/*
 * sets cell fo given cordinates to color of player which is on move (beginng with black)
 * returns 1 if the move was winning 0 otherwais
 */
int put_stone(int *board, int size, int x, int y);