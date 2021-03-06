#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gomlogic.h"

#define DELAULT_BOARD_SIZE 15
#define HELLP "Console Gomoku Game\n" "FLAGS:\n" " -s     --size          Size of game board.\n" " -h     --hellp         Prints hellp menu.\n"

#define OK_CONTINUE 128

/*
 * processes the args
 * !! in some cases can call exit and end the program !!
 */ 
int process_args(int argc, char* argv[]);

int main(int argc, char* argv[]) {
    int size = process_args(argc, argv);

    int *board = alloc_board(size);
    if (board == NULL) {
        fprintf(stderr, "error: not anought free space to allocate board\n");
        return EXIT_FAILURE;
    }
    printf("Board %ix%i alocated\n", size, size);

    // test
    printboard(board, size);
    put_stone(board,size, 3, 2);
    put_stone(board,size, 1, 1);
    put_stone(board,size, 2, 3);
    put_stone(board,size, 0, 0);
    put_stone(board,size, 0, 12);
    put_stone(board,size, 12, 0);
    put_stone(board,size, 4, 4);
    printboard(board, size);

    // TODO game

    free(board);
    return EXIT_SUCCESS;
}


/*
 * processes the args
 * !! in some cases can call exit and end the program !!
 */
int process_args(int argc, char* argv[]) {
    int size = DELAULT_BOARD_SIZE;

    /* process args */
    for (int i=1; i<argc; ++i) {
        // valid flag starts with '-' and continues with a char
        if (argv[i][0] != '-' || argv[i][1] == '\0') {
            fprintf(stderr, "error: argument %i expected to be flag\n", i);
            exit(EXIT_FAILURE);
        }

        if (strcmp(argv[i], "-s") == 0) {
            // counter incremented in side clycle
            // next arg is not expected to be a flag so ti doesn't have to be tested as a flag
            ++i;
            if (i >= argc) {
                fprintf(stderr,
                        "error: argument %i is size flag, argument %i is expected\n", i-1, i);
                exit(EXIT_FAILURE);
            }

            size = atoi(argv[i]);
            if (size < WINNING) {
                fprintf(stderr,
                        "error: the size of the board (%i) is lower then winning number of stones in the row (%i)\n", size, WINNING);
                exit(EXIT_FAILURE);
            }
            continue;
        }
        if (strcmp(argv[i], "-h") == 0) {
            printf(HELLP);
            // if hellp flag passed no other flags matter
            exit(EXIT_SUCCESS);

        }
        if (argv[i][1] == '-') {
            if (strcmp(argv[i], "--size") == 0) {
                // counter incremented in side clycle
                // next arg is not expected to be a flag so ti doesn't have to be tested as a flag
                ++i;
                if (i >= argc) {
                    fprintf(stderr,
                            "error: argument %i is size flag, argument %i is expected\n", i-1, i);
                    exit(EXIT_FAILURE);
                }

                size = atoi(argv[i]);
                if (size < WINNING) {
                    fprintf(stderr,
                            "error: the size of the board (%i) is lower then winning number of stones in the row (%i)\n", size, WINNING);
                    exit(EXIT_FAILURE);
                }
                continue;
            }
            if (strcmp(argv[i], "--hellp") == 0) {
            printf(HELLP);
            // if hellp flag passed no other flags matter
            exit(EXIT_SUCCESS);
            }
        } // end if
        fprintf(stderr, "error: argument %i is unknowen flag\n", i);
        exit(EXIT_FAILURE);
    } // end for

    return size;
}