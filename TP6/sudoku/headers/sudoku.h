#ifndef __SUDOKU__
#define __SUDOKU__

typedef int Board[9][9];

void initialize_empty_board(Board grid);
void print_board(Board grid);
int sudoku_solver(Board grid, int position);
int check_row(Board grid, int row, int current);
int check_column(Board grid, int column, int current);
int check_box(Board grid, int bRow, int bColumn, int current);
int is_safe(Board grid, int row, int column, int current);

#endif
