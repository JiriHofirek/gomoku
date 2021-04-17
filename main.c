#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gomlogic.h"

#define DELAULT_BOARD_SIZE 15
#define HELLP "-s    --size    Size of game board.\n" "-h    --hellp    Prints hellp menu.\n"



int main(int argc, char* argv[]) {
    int size = DELAULT_BOARD_SIZE;

    /* process args */
    for (int i=1; i<argc; ++i) {
        // valid flag starts with '-' and continues with a char
        if (argv[i][0] != '-' || argv[i][1] == '\0') {
            fprintf(stderr, "error: argument %i expected to be flag\n", i);
            return EXIT_FAILURE;
        }

        if (argv[i][1] == 's') {
            // counter incremented in side clycle
            // next arg is not expected to be a flag so ti doesn't have to be tested as a flag
            ++i;
            if (i >= argc) {
                fprintf(stderr,
                        "error: argument %i is size flag, argument %i is expected\n", i-1, i);
                return EXIT_FAILURE;
            }

            size = atoi(argv[i]);
            if (size < WINNING) {
                fprintf(stderr,
                        "error: the size of the board (%i) is lower then winning number of stones in the row (%i)\n", size, WINNING);
                return EXIT_FAILURE;
            }
            continue;

        } else if (argv[i][1] == 'h') {
            printf(HELLP);
            // if hellp flag passed no other flags matter
            return EXIT_SUCCESS;

        } else if (argv[i][1] == '-') {
            if (strcmp(argv[i], "--size") == 0) {
                // TODO
            } else if (strcmp(argv[i], "--hellp") == 0) {
            printf(HELLP);
            // if hellp flag passed no other flags matter
            return EXIT_SUCCESS;
            }
        }
        
    } // end for

    int *board = alloc_board(size);
    if (board == NULL) {
        fprintf(stderr, "error: not anought free space to allocate board\n");
        return EXIT_FAILURE;
    }
    printf("Board %ix%i alocated\n", size, size);


    free(board);
    return EXIT_SUCCESS;
}