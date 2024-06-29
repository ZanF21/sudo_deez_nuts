#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class sudoku {

public:
  vector<int> board;
  vector<set<int>> possible_moves;

  sudoku() {
    board = vector<int>(81, 0);
    possible_moves = vector<set<int>>(81, set<int>());
  }

  void board_input();
  void print_board();
  void get_possible_moves();
  void ask_possible_moves();
  void print_possible_moves(int x, int y);
  void fill_in_single_possible_moves();
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

void sudoku::get_possible_moves() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (board[i * 9 + j] == 0) {
        set<int> *possible = &possible_moves[i * 9 + j];
        for (int k = 1; k <= 9; k++) {
          possible->insert(k);
        }
        for (int k = 0; k < 9; k++) {
          possible->erase(board[i * 9 + k]);
          possible->erase(board[k * 9 + j]);
        }
        int x = i / 3, y = j / 3;
        for (int k = 0; k < 3; k++) {
          for (int l = 0; l < 3; l++) {
            possible->erase(board[(x * 3 + k) * 9 + (y * 3 + l)]);
          }
        }
      }
    }
  }
}

void sudoku::ask_possible_moves() {
  int x, y;
  cout << "Enter the cell (x,y) : ";
  cin >> x >> y;
  print_possible_moves(x, y);
}

void sudoku::print_possible_moves(int x, int y) {
  cout << "Possible moves are : ";
  for (auto i : possible_moves[(x - 1) * 9 + (y - 1)]) {
    cout << i << " ";
  }
  cout << "\n";
}

int main() {
  sudoku s;
  s.board_input();
  s.print_board();
  s.get_possible_moves();
  for (int i = 0; i < 81; i++) {
    if (s.board[i] == 0) {
      cout << "Possible moves of (" << i / 9 + 1 << ", " << i % 9 + 1 << ") : ";
      for (auto j : s.possible_moves[i]) {
        cout << j << " ";
      }
      cout << "\n";
    }
  }

  return 0;
}
