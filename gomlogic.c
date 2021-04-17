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