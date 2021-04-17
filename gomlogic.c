#include "gomlogic.h"



/* creats 1D feeld whitch represtns 2D feeld of game board
 * sets all cells in the feeld EMPTY
*/
int *alloc_board(int size) {
    int cells_count = size * size;
    
    int *board = malloc(cells_count * sizeof(int));
    if (board == NULL)
        return NULL;

    for (int i=0; i<cells_count; ++i) {
        board[i] = EMPTY;
    }

    return board;
}

/*
 * sets cell fo given cordinates to color of player which is on move (beginng with black)
 * returns 1 if the move was winning 0 otherwais
 */
int put_stone(int *board, int size, int x, int y) {
    static int onmove=BLACK;
    
    board[(y-1) * size + x-1] = onmove;
    
    // TODO chack if wined
    
    onmove = (onmove == BLACK) ? WHITE : BLACK; 
    return 0;
}
