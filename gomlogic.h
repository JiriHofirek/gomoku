#include <stdlib.h>

#define EMPTY 0
#define WHITE 1
#define BLACK 2
// number of stones in the row whitch is winning
#define WINNING 5



/* creats 1D feeld whitch represtns 2D feeld of game board
 * sets all cells in the feeld EMPTY
*/
int *alloc_board(int size);