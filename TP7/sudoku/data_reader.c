#include <stdio.h>

#include "headers/data_reader.h"

int fread_board(const char* file, Board* board){
	FILE* f;
	int row, column;
	int entry;

	f = fopen(file, "r");
	if (f == NULL)
	{
		fprintf(stderr, "file \"%s\" does not exist ...\n", file);
		return 0;
	}

	for (row = 0; row < 9; row++)
	{
		for (column = 0; column < 9; column++)
		{
			fscanf(f, "%d", &entry);
			board->board[row][column] = entry;

			if(entry > 0)
				board->empty_counter--;
		}
	}
	return 1;
}

void fill_numeric_pad(Board* pad)
{
	int row, column, counter;
	counter = 0;

	for(row = 0; row < 3; row++)
		for(column = 0; column < 3; column++)
		{
			counter++;
			pad->board[row][column] = counter;
		}
}