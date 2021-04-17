#include <stdlib.h>
#include <stdio.h>

#include "gomlogic.h"

#define DELAULT_BOARD_SIZE 15
#define HELP "-s    --size    Size of game board.\n" "-h    --help    Prints help menu.\n"



int main(int argc, char* argv[]) {
    int size = DELAULT_BOARD_SIZE;

    /* process args */
    for (int i=1; i<argc; ++i) {
        // valid flag starts with '-' and continues with a char
        if (argv[i][0] != '-' || argv[i][1] != '\0') {
            fprintf(stderr, "error: argument %i expected to be flag", i);
            return EXIT_FAILURE;
        }

        if (argv[i][1] == 's') {
            ++i;
            if (i >= argc) {
                fprintf(stderr,
                        "error: argument %i is size flag, argument %i is expected", i-1, 1);
                return EXIT_FAILURE;
            }
        }
    }

    int *board = alloc_board(size);
    if (board == NULL) {
        fprintf(stderr, "error: not anought free space to allocate board");
        return EXIT_FAILURE;
    }


    free(board);
    return EXIT_SUCCESS;
}