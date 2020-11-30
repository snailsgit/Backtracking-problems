#include <bits/stdc++.h>
using namespace std;
int board[11][11];
bool isPossible(int n, int row, int col) {

  for (int j = row - 1; j >= 0; j--) {
    if (board[j][col] == 1) {
      return false;
    }
  }

  for (int i = row - 1, j = col - 1; j >= 0 && i >= 0; j--, i--) {
    if (board[i][j] == 1) {
      return false;
    }
  }

  for (int i = row - 1, j = col + 1; j < n && i >= 0; j++, i--) {
    if (board[i][j] == 1) {
      return false;
    }
  }

  return true;
}
void helper(int n, int row) {
  if (row == n) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << board[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
    return;
  }

  for (int j = 0; j < n; j++) {
    if (isPossible(n, row, j)) {
      board[row][j] = 1;
      helper(n, row + 1);
      board[row][j] = 0;
    }
  }

  return;
}
void placeNQueens(int n) {
  memset(board, 0, 11 * 11 * sizeof(int));
  helper(n, 0);
}

int main() {

  int n;
  cin >> n;
  placeNQueens(n);
}
