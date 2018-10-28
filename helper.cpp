#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include "helper.h"


using namespace std;


/* Function to check if digit is not doubled in the row, column, sub-board */
bool check_entry_valid(int row_index, int col_index, char digit, char board[9][9]) 
{
  int i,j;

  /* Check position is unoccupied */

  if (!(board[row_index][col_index] == '.')) 
    return false;

  /* Check if row is valid */

  for (i=0; i<9; i++) 
    if (i != col_index && board[row_index][i] == digit)
      return false;


  /* Check if column is valid */

  for (i=0; i<9; i++)
    if (i != row_index && board[i][col_index] == digit)
      return false;

  /* Check if 3x3 sub-board is valid */

  for (i = (row_index/3) * 3; i < (row_index/3) * 3 + 3; i++)
    for (j = (col_index/3) * 3; j < (col_index/3) * 3 + 3; j++)
      if (i != row_index && j != col_index && board[i][j] == digit)
        return false;

  return true;
}


/* Function to check if position on board is valid */
bool check_position_valid(const char position[2]) {

   /* Only works for capital letters */

 if(strlen(position) != 2) {
  return false;
 }

 if (! ( (position[0] >= 'A' && position[0] <= 'I') && (position[1] > 47 && position[1] <= 57) ) ) 
    return false; 

 
 return true;
}


/* Function to complete a Sudoku board recursively */
bool board_solution(char test_board[9][9], int row_index, int col_index) {

  /* Check if function reaches end of board */
  if (row_index == 9)
    return true;

  /* Check if cell is pre-filled in */
  if (test_board[row_index][col_index] != '.') {
    if (board_solution(test_board,col_index == 8? (row_index + 1) : row_index, (col_index + 1) % 9))
      return true;
  }

  else {

    /* Array of digits to be put in empty cells */
    char digits[9] = {'1','2','3','4','5','6','7','8','9'};

    for(int i=0; i<9; i++){

      /* Check for duplicates in this row, colum and sub-board */
      if(check_entry_valid(row_index,col_index,digits[i],test_board)) {
         test_board[row_index][col_index] = digits[i];

        /* Move to next cell left to right, up to down */
        if(board_solution(test_board,col_index == 8? (row_index + 1) : row_index, (col_index + 1) % 9))
          return true;

        else {
            
          /* Initialize the cell when backtracking if the value in the next cell was not valid */
          test_board[row_index][col_index] = '.';
        }

      }

    }
  }

  return false;
}


