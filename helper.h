#ifndef HELPER_H
#define HELPER_H

bool check_entry_valid(int row_index, int col_index, char digit, char board[9][9]);
bool check_position_valid(const char position[3]);
bool board_solution(char test_board[9][9], int row_index, int col_index);


#endif 
