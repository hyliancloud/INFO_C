### Makefile of Slider Puzzle Project ###

CC=gcc
CFLAGS=-Wall -ansi -g -std=c99
OBJ=$(OBJPATH)game.o $(OBJPATH)slider.o $(OBJPATH)input_manager.o $(OBJPATH)mlv_board.o $(OBJPATH)slider_helper.o
OBJPATH=obj/
SRCPATH=src/
LDFLAGS=-lMLV -lm

all : slider
	@echo "--------------------------------------------------------------"
	@echo "             Slider Puzzle Game - C Programming"
	@echo "                      Emilie Marti"
	@echo ""
	@echo "           to execute type: ./bin/slider data/pic"
	@echo "--------------------------------------------------------------"

slider: dir $(OBJ)
	$(CC) -o bin/slider $(OBJ) $(LDFLAGS)

dir:
	mkdir -p bin obj

$(OBJPATH)game.o: $(SRCPATH)game.c
	$(CC) -c $(SRCPATH)game.c -o $(OBJPATH)game.o $(CFLAGS) -lMLV

$(OBJPATH)slider.o: $(SRCPATH)slider.c
	$(CC) -c $(SRCPATH)slider.c -o $(OBJPATH)slider.o $(CFLAGS) -lMLV

$(OBJPATH)input_manager.o: $(SRCPATH)input_manager.c
	$(CC) -c $(SRCPATH)input_manager.c -o $(OBJPATH)input_manager.o $(CFLAGS) -lMLV

$(OBJPATH)mlv_board.o: $(SRCPATH)mlv_board.c
	$(CC) -c $(SRCPATH)mlv_board.c -o $(OBJPATH)mlv_board.o $(CFLAGS) -lMLV

$(OBJPATH)slider_helper.o: $(SRCPATH)slider_helper.c
	$(CC) -c $(SRCPATH)slider_helper.c -o $(OBJPATH)slider_helper.o $(CFLAGS) -lMLV

clean:
	rm -f $(OBJ)
	rm -f bin/slider
