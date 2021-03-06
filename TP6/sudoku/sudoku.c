#include <stdio.h>

#include "headers/sudoku.h"

void initialize_empty_board(Board grid)
{
	int row, column;

	for(row = 0; row < 9; row++)
		for(column = 0; column < 9; column++)
			grid[row][column] = 0;
}

void print_board(Board grid)
{
	int row, column;

	for(row = 0; row < 9; row++)
	{
		for(column = 0; column < 9; column++)
			printf("----");

		printf("-\n");

		for(column = 0; column < 9; column++)
		{
			if(grid[row][column] == 0) printf("|   ");
			else printf("| %d ", grid[row][column]);
		}
		printf("|\n");
	}

	for(row = 0; row < 9; row++)
		printf("----");

	printf("-\n");
}

int sudoku_solver(Board grid, int position)
{
	int num, row, column;

	row = position/9;
	column = position%9;

	if(position == 81)
		return 1;
	if(grid[row][column] != 0) return sudoku_solver(grid, position+1);

	for(num = 1; num <= 9; num++)
	{
		if(is_safe(grid, row, column, num) == 1)
		{
			grid[row][column] = num;
			if(sudoku_solver(grid, position+1) == 1) return 1;
			else grid[row][column] = 0;
		}
	}

	return 0;
}

int check_row(Board grid, int row, int current)
{
	int column;

	for(column = 0; column < 9; column++)
		if(grid[row][column] == current) return 0;

	return 1;
}

int check_column(Board grid, int column, int current)
{
	int row;

	for(row = 0; row < 9; row++)
		if(grid[row][column] == current) return 0;

	return 1;
}

int check_box(Board grid, int row, int column, int current)
{
	int boxRow, boxColumn;

	boxRow = row - (row%3);
	boxColumn = column - (column%3);

	for(row = boxRow; row < boxRow+3; row++)
		for(column = boxColumn; column < boxColumn+3; column++)
			if(grid[row][column] == current) return 0;

	return 1;
}

int is_safe(Board grid, int row, int column, int current)
{
	if(check_row(grid, row, current) == 1
		&& check_column(grid, column, current) == 1
		&& check_box(grid, row, column, current) == 1) return 1;
	else return 0;
}