# Makefile TP 9 INFO1

CC = gcc
CFLAGS = -Wall -ansi -g
OBJ = firsts_steps.o alloc_2D.o alloc_arg.o more_alloc.o main.o

all : tp9 clean
	@echo "--------------------------------------------------------------"
	@echo "       Dynamic Memory Allocation - C programming TP9"
	@echo "                       Emilie Marti"
	@echo ""
	@echo "                 to execute type: ./TP9"
	@echo "--------------------------------------------------------------"

main.o :
	gcc $(CFLAGS) -c main.c

firsts_steps.o :
	gcc $(CFLAGS) -c firsts_steps.c

alloc_2D.o :
	gcc $(CFLAGS) -c alloc_2D.c

alloc_arg.o :
	gcc $(CFLAGS) -c alloc_arg.c

more_alloc.o :
	gcc $(CFLAGS) -c more_alloc.c

tp9 : $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o TP9

clean :
	rm -f *.o