#include <iostream>
#include <cstdio>
#include "sudoku.h"
#include <time.h>

using namespace std;

int main() {

  char board[9][9];

  /* This section illustrates the use of the pre-supplied helper functions. */
  cout << "============= Pre-supplied functions =============" << endl << endl;

  cout << "Calling load_board():" << endl;
  load_board("easy.dat", board);

  cout << endl << "Displaying Sudoku board with display_board():" << endl;
  display_board(board);
  cout << "Done!" << endl << endl;

  cout << "=================== Question 1 ===================" << endl << endl;

  /*Edge cases:
  - what if array is empty
  - what if array has space not dot '.' 
  */

  load_board("easy.dat", board);
  cout << "Board is ";
  if (!is_complete(board))
    cout << "NOT ";
  cout << "complete." << endl << endl;

  load_board("easy-solution.dat", board);
  cout << "Board is ";
  if (!is_complete(board))
    cout << "NOT ";
  cout << "complete." << endl << endl;


  /* Edge case 1: input filename doesn't exist 
  load_board("", board);
  if (save_board("easy-copy1.dat", board))
    cout << "Save board to 'easy-copy1.dat' successful." << endl;
  else
    cout << "Save board failed." << endl;
  cout << endl;*/


  /* Edge case 2: board is smaller than expected 
  load_board("easy_wrong_dimension.dat", board);
  if (save_board("easy-copy2.dat", board))
    cout << "Save board to 'easy-copy3.dat' successful." << endl;
  else
    cout << "Save board failed." << endl;
  cout << endl;*/


  cout << "=================== Question 2 ===================" << endl << endl;


  load_board("easy.dat", board);

  // Should be OK
  cout << "Putting '1' into I8 is ";
  if (!make_move("I8", '1', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << endl;
  display_board(board);


  /* Edge case 1: position starts with lower-case 
  cout << "Putting '1' into a8 is ";
  if (!make_move("a8", '1', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << endl;
  display_board(board);*/


  /* Edge case 2: position is null 
  cout << "Putting '1' into _ is ";
  if (!make_move("", '1', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << endl;
  display_board(board);*/


  /* Edge case 3: position is out of bounds  
  cout << "Putting '1' into K7 is ";
  if (!make_move("K7", '1', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << endl;
  display_board(board);*/


  /* Edge case 4: position is made of letter followed by 2 digits 
  cout << "Putting '1' into C38 is ";
  if (!make_move("C28", '1', board)) 
    cout << "NOT ";
  cout << "a valid move. The board is:" << endl;
  display_board(board);*/

  cout << "=================== Question 3 ===================" << endl << endl;

 
  load_board("easy.dat", board);
  if (save_board("easy-copy.dat", board))
    cout << "Save board to 'easy-copy.dat' successful." << endl;
  else
    cout << "Save board failed." << endl;
  cout << endl;


   /* Edge case 1: filename doesn't exist 
  load_board("easy.dat", board);
  if (save_board("", board))
    cout << "Save board to '' successful." << endl;
  else
    cout << "Save board failed." << endl;
  cout << endl;*/


  /* Edge case 2: board is empty 
  char empty_board[9][9];

  if (save_board("easy-copy.dat3", empty_board))
    cout << "Save board to 'easy-copy3.dat' successful." << endl;
  else
    cout << "Save board failed." << endl;
  cout << endl;*/

  /*
  - how do we check if file was succesfully written? same size as input array? 
   */


  cout << "=================== Question 4 ===================" << endl << endl;


  load_board("easy.dat", board);
  if (solve_board(board)) {
    cout << "The 'easy' board has a solution:" << endl;
    display_board(board);
  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;

  load_board("medium.dat", board);
  if (solve_board(board)) {
    cout << "The 'medium' board has a solution:" << endl;
    display_board(board);
  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;

  /* Edge case 1: input array is empty (not pre-filled positions) 
  load_board("easy-empty.dat", board);
  if (solve_board(board)) {
    cout << "The 'easy-empty board has a solution:" << endl;
    display_board(board);
  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;*/

  /* Edge case 2: input array is completed 
  load_board("easy-solution.dat", board);
  if (solve_board(board)) {
    cout << "The 'easy-solution board has a solution:" << endl;
    display_board(board);
  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;*/




  cout << "=================== Question 5 ===================" << endl << endl;


/* Declare time variables to calculate runtime for solving each board */
clock_t t1, t2, t3, t4, t5, t6;

/* Attempt to solve 1st mystery board */
t1 = clock();

  load_board("mystery1.dat", board);
  if (solve_board(board)) {
    cout << "The 'mystery1.dat' board has a solution:" << endl;
    display_board(board);
  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;

t2 = clock();

float diff = ((float)t2-(float)t1);
float seconds = diff / CLOCKS_PER_SEC;
cout<< seconds <<endl;
cout<< endl;


/* Attempt to solve 2nd mystery board */
t3 = clock();

  load_board("mystery2.dat", board);
  if (solve_board(board)) {
    cout << "The 'mystery2.dat' board has a solution:" << endl;
    display_board(board);
  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;

t4 = clock();

diff = ((float)t4-(float)t3);
seconds = diff / CLOCKS_PER_SEC;
cout<< seconds <<endl;
cout<< endl;


/* Attempt to solve 3rd mystery board */
t5 = clock();

  load_board("mystery3.dat", board);
  if (solve_board(board)) {
    cout << "The 'mystery3.dat board has a solution:" << endl;
    display_board(board);
  } else 
    cout << "A solution cannot be found." << endl;
  cout << endl;

t6 = clock();

diff = ((float)t6-(float)t5);
seconds = diff / CLOCKS_PER_SEC;
cout<< seconds <<endl;
cout<< endl;


  return 0;
}
