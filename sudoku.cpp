#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include "sudoku.h"
#include "helper.h"

using namespace std;

/* You are pre-supplied with the functions below. Add your own 
   function definitions to the end of this file. */

/* Pre-supplied function to load a Sudoku board from a file */
void load_board(const char* filename, char board[9][9]) {

  cout << "Loading Sudoku board from file '" << filename << "'... ";

  ifstream in(filename);
  if (!in)
    cout << "Failed!" << endl;
  assert(in);

  char buffer[512];

  int row = 0;
  in.getline(buffer,512);
  while (in && row < 9) {
    for (int n=0; n<9; n++) {
      assert(buffer[n] == '.' || isdigit(buffer[n]));
      board[row][n] = buffer[n];
    }
    row++;
    in.getline(buffer,512);
  }

  cout << ((row == 9) ? "Success!" : "Failed!") << endl;
  assert(row == 9);
}

/* Internal helper function */
void print_frame(int row) {
  if (!(row % 3))
    cout << "  +===========+===========+===========+" << endl;
  else
    cout << "  +---+---+---+---+---+---+---+---+---+" << endl;
}

/* Internal helper function */
void print_row(const char* data, int row) {
  cout << (char) ('A' + row) << " ";
  for (int i=0; i<9; i++) {
    cout << ( (i % 3) ? ':' : '|' ) << " ";
    cout << ( (data[i]=='.') ? ' ' : data[i]) << " ";
  }
  cout << "|" << endl;
}

/* Pre-supplied function to display a Sudoku board */
void display_board(const char board[9][9]) {
  cout << "    ";
  for (int r=0; r<9; r++) 
    cout << (char) ('1'+r) << "   ";
  cout << endl;
  for (int r=0; r<9; r++) {
    print_frame(r);
    print_row(board[r],r);
  }
  print_frame(9);
}

/* Add your functions here */

/////////////////////////////// QUESTION 1 //////////////////////////////////

/* Function to check if the Sudoku board is complete */
bool is_complete(const char board[9][9]) {
  
  for (int i=0; i<9; i++) {
      for (int j=0; j<9; j++){
          if (board[i][j] == '.')
            return false;
        }
    }
  return true;
}


/////////////////////////////// QUESTION 2 //////////////////////////////////

/* Function to place a digit onto a Sudoku board at a given position */
bool make_move(const char position[3], char digit, char board[9][9]) {
  
  int row_index, col_index;

  row_index = (int) position[0] - 65; /*ASCII code for A is 65; i is 1st index*/
  col_index = (int) position[1] - 49; /*ASCII code for 1 is 49; j is 2nd index*/


  if ( (check_entry_valid(row_index,col_index,digit,board) ) && (check_position_valid(position) ) ) {

    /* Update board */
    board[row_index][col_index] = digit;
    return true;
  }

  else  
    return false; 

}

/////////////////////////////// QUESTION 3 //////////////////////////////////

/* Function to save the board to a file */
bool save_board(const char* filename, char board[9][9]) {


  ofstream out_stream;
  out_stream.open(filename);

  /* Check if output filename is empty */

  if(!strcmp(filename,"")) {
    cout<< "Input filename is empty!" << endl;
    return false;
  }

  /* Check output file exists  */

  if(!out_stream)
    return false;

  /* Check board is not empty */

  for (int i=0; i<9; i++) 
    for (int j=0; j<9; j++) 
      if(board[i][j] == '\0') {
        cout<<"Board is empty" << endl;
        return false;
      }

  /* Write the board to file  */

  if(out_stream.is_open())
  {

    for (int i=0; i<9; i++) {
      for (int j=0; j<9; j++) {
        out_stream << board[i][j];
      }
      out_stream << endl;
    }
  }

  else {
    cout<< "Error opening file" << endl;
    return false;
  }

 out_stream.close();
   
 return true;

}

/////////////////////////////// QUESTION 4 //////////////////////////////////

/* Function to solve Sudoku board */
bool solve_board(char board[9][9]) {

  char test_board[9][9];

  /* Clone initial board into a modifiable copy  */

  for (int i=0; i<9; i++) {
    for (int j=0; j<9; j++) {
      test_board[i][j] = board[i][j];
      cout<< test_board[i][j];
    }

    cout << endl;
  }

  /* Check if board is solvable */

  if(board_solution(test_board,0,0)){

    /* Copy test_board into board if solution found */

    for (int i=0; i<9; i++) {
      for (int j=0; j<9; j++) {
        board[i][j] = test_board[i][j];
      }
    cout << endl;
    }
      
    return true; 
  }

  else 
    return false; 

}


















