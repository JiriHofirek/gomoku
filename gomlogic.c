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
 * returns 1 if the move was winning, -1 if move is ilegal, 0 otherwais
 */
int put_stone(int *board, int size, int x, int y) {
    static int onmove=BLACK;

    if (x <= 0 || x > size || y <= 0 || y > size ||
            board[(y-1) * size + x-1] != EMPTY)
        return -1; // ilegal move
    
    board[(y-1) * size + x-1] = onmove;
    
    // TODO chack if wined
    
    onmove = (onmove == BLACK) ? WHITE : BLACK; 
    return 0;
}

// 6 - - - - - -
// 5 - - - - - -
// 4 - - - - - -
// 3 - - - - - -
// 2 - - - - - -
// 1 - - - - - -
// . a b c d e f
void printboard(int *board, int size) {
    printf("state on board:\n");
    // cycle throw lines
    for (int i=size-1; i>=0; --i) {
        // cycle throw rows
        for (int j=0; j<size; j++) {
            if (board[i * size + j] == BLACK)
                printf("X  ");
            else if (board[i * size + j] == WHITE)
                printf("O  ");
            else
                printf("-  ");
        }
        printf("\n");
    }
}