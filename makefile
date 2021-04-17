MAIN=main
LOG=gomlogic
SRCS=$(MAIN).c $(LOG).c
OUT=gomoku
CFLAGS=-g -Wall -pedantic-errors -Werror

edit : $(SRCS)
	gcc -o $(OUT) $(SRCS) $(CFLAGS)

main : $(MAIN).c
	gcc -c -o $(MAIN)o $(MAIN).c $(CFLAGS)

logic : $(LOG)
	gcc -c -o $(LOG).o $(LOG).c $(CFLAGS)

clean :
	rm *.o $(OUT)
