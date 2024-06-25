#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class sudoku {

public:
  vector<int> board;
  vector<vector<int>> possible_moves;

  sudoku() {
    board = vector<int>(81, 0);
    possible_moves = vector<vector<int>>(81, vector<int>());
  }

  void board_input();
  void print_board();
};

void sudoku::board_input() {
  cout << "Enter the board (9 at a time) (0 for empty) : \n";
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cin >> board[i * 9 + j];
    }
  }
}

void sudoku::print_board() {
  cout << "|-----------------|\n|";
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << (board[i * 9 + j] == 0 ? 0 : board[i * 9 + j]) << "|";
    }
    cout << "\n|-----------------|\n|";
  }
  cout << "\b";
}

int main() {
  sudoku s;
  s.board_input();
  s.print_board();
  return 0;
}
