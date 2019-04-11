#include <stdio.h>
#include <stdlib.h>

#define console_WIDTH 512
#define console_HEIGHT 512

#define PUZZLE_SIZE 4

typedef struct _square
{
	int row;
	int column;
	int data;
} Square;

typedef struct _board
{
	Square grid[PUZZLE_SIZE][PUZZLE_SIZE];
} Board;

typedef enum _direction
{
	NONE,
	UP,
	DOWN,
	LEFT,
	RIGHT
} Direction;

/**
 * Initialize board structure and give the number of the boxes
 * Then assign 0 to the last box (which will simulate the empty box)
 */
void initialize_board(Board* board)
{
	int row, column, counter;

	counter = 0;

	for(row = 0; row < PUZZLE_SIZE; ++row)
	{
		for(column = 0; column < PUZZLE_SIZE; ++column)
		{
			board->grid[row][column].row = row;
			board->grid[row][column].column = column;

			board->grid[row][column].data = counter;

			counter++;
		}
	}

	board->grid[row-1][column-1].data = -1;
}

/**
 * Print the board in terminal
 */
void print_board(Board* board)
{
	int row, column;

	for(row = 0; row < PUZZLE_SIZE; row++)
	{
		for(column = 0; column < PUZZLE_SIZE; column++)
			printf("-----");

		printf("-\n");

		for(column = 0; column < PUZZLE_SIZE; column++)
		{
			if((board->grid)[row][column].data == -1)
				printf("|    ");
			else
			{
				if(((board->grid)[row][column]).data >= 10)
					printf("| %d ", ((board->grid)[row][column]).data);
				else
					printf("| %d  ", ((board->grid)[row][column]).data);
			}
		}
		printf("|\n");
	}

	for(row = 0; row < PUZZLE_SIZE; row++)
		printf("-----");

	printf("-\n");
}

/**
 * Return the available box (empty box next to the current box)
 * Return NONE if there is none
 */
Direction check_empty(Board* board, Square box)
{
	if(board->grid[box.row][box.column-1].data == -1)
		return UP;
	if(board->grid[box.row][box.column+1].data == -1)
		return DOWN;
	if(board->grid[box.row+1][box.column].data == -1)
		return RIGHT;
	if(board->grid[box.row-1][box.column].data == -1)
		return LEFT;
	
	return NONE;
}

/**
 * Change the case data, essentially data will go to the direction choosen
 * and current box will be emptied
 */
void move_to(Board* board, Square box, Direction direction)
{
	printf("data = %d \tboard[%d][%d]\n", board->grid[box.row][box.column].data, box.row, box.column);
	if(direction == NONE)
		return;
	else if(direction == UP)
		board->grid[box.row][box.column-1].data = board->grid[box.row][box.column].data;
	else if(direction == DOWN)
		board->grid[box.row][box.column+1].data = board->grid[box.row][box.column].data;
	else if(direction == RIGHT)
		board->grid[box.row+1][box.column].data = board->grid[box.row][box.column].data;
	else
		board->grid[box.row-1][box.column].data = board->grid[box.row][box.column].data;
	
	board->grid[box.row][box.column].data = -1;
}

/**
 * Calls move_to with the returned value of check_empty
 * If there is an empty adjacent box, the current box will be moved
 * if not, nothing happens
 */
void move_square(Board* board, Square box)
{
	Direction direction = check_empty(board, box);

	printf("Chosen Direction = %d\tboard[%d][%d]\n", direction, box.row, box.column);

	move_to(board, box, direction);
}

int get_column(int position)
{
	return position%PUZZLE_SIZE;
}

int get_row(int position)
{
	return position/PUZZLE_SIZE;
}

int main(int argc, char** argv)
{
	Board board;

	initialize_board(&board);
	print_board(&board);

	int input;
	printf("choose a number\n");
	scanf("%d", &input);

	int row = get_row(input);
	int column = get_column(input);

	printf("\nposition = %d\tboard[%d][%d]\n", input, row, column);

	Square chosenBox = board.grid[row][column];

	move_square(&board, chosenBox);

	print_board(&board);

	printf("choose a number\n");
	scanf("%d", &input);

	

	return 0;
}