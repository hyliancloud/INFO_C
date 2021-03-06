#include <MLV/MLV_all.h>
#include <stdio.h>
#include <time.h>

#include "headers/board.h"
#include "headers/sudoku.h"
#include "headers/input_manager.h"
#include "headers/data_reader.h"
#include "headers/turn_manager.h"

void game(Board* sudoku, Board* inGameSudoku, Board* numPad)
{
    int sudokuSize, numSize;
    int position, padPosition;
    int row, column, padRow, padColumn;

    sudokuSize = 9;
    numSize = 3;

    /* Create numeric pad */
    fill_numeric_pad(numPad);

    /* MLV background */
    MLV_create_window("ｓｕｄｏｋｕ　（よリ哀)", "background", console_WIDTH, console_HEIGHT);

    MLV_Font* font = MLV_load_font("data/font.ttf", 20);

    int running = 1;

    /* Debug Mode - Get the final screen without actually winning
    win_the_game();*/
    
    double time = 0;

    while(running)
    {
        MLV_clear_window(MLV_COLOR_BLACK);

        /* Display the background and the inGame board */
        display_background();
        display_board(inGameSudoku, 9, font);

        time = clock()/CLOCKS_PER_SEC;
        display_time(time, font);
        
        MLV_actualise_window();

        /* Check if the in-game board is full */
        if(inGameSudoku->empty_counter == 0)
            running = 0;

        /* Get the player's input on the in-game board */
        position = get_input(sudokuSize);
        row = position / sudokuSize;
        column = position - row*sudokuSize;

        if(position != -2)
        {
            /* If player clicks out of the board */
            if(position == -1)
            {
                /* Keep waiting for next move */
                animate_writing("out of board ...");
            }
            /* If player clicks on an unchangeable case */
            else if(sudoku->board[column][row] != 0)
            {
                /* Keep waiting for next move */
                animate_writing("cannot change value ...");
            }
            else
            {
                padPosition = -2;
                
                while(padPosition == -2)
                {
                    /* Display the numeric pad */
                    display_board(numPad, 3, font);
                    MLV_actualise_window();
                    
                    /* Get the player's input on the numeric pad */
                    padPosition = get_input(numSize);

                    padRow = padPosition / numSize;
                    padColumn = padPosition - padRow*numSize;

                    /* If the number chosen is safe */
                    if(is_safe(inGameSudoku, column, row, numPad->board[padColumn][padRow]))
                    {
                        /* If the case was empty before, decrease the empty counter */
                        if(inGameSudoku->board[column][row] == 0)
                            inGameSudoku->empty_counter--;

                        /* Add the chosen number to the in-game board */
                        inGameSudoku->board[column][row] = numPad->board[padColumn][padRow];   
                    }
                }
            }

        }

        MLV_clear_window(MLV_COLOR_BLACK);
    }
    
    win_the_game();
}

void win_the_game()
{
    MLV_clear_window(MLV_COLOR_BLACK);

    /* Display the background */
    display_background();        
    MLV_actualise_window();

    animate_writing("Congratulations, you won !");
    MLV_wait_seconds(5.0f);
    
    quit_game();
}

void quit_game()
{
    animate_writing("you quit the game !");
    MLV_actualise_window();

    MLV_wait_seconds(2.0f);

    exit(0);
}