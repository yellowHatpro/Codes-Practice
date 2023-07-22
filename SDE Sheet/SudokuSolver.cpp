#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isPossible(vector<vector<char>>&board, int i, int j, char ch){
      for(int x = 0; x<9; x++){
        if (board[x][j]==ch) return false;
        if (board[i][x]==ch) return false;
        if (board[3*(i/3)+x/3][3*(j/3)+x%3]==ch) return false;
      }
      return true;
    }

    bool f(vector<vector<char>>&board){
      for(int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++) {
          if (board[i][j]=='.'){
          for(char ch = '1' ; ch<='9'; ch++){
            if (isPossible(board,i,j,ch)){
              board[i][j]=ch;
              if (f(board)){
                return true;
            } else {
                board[i][j]='.';
              }
            }
          }  
            return false;
        }       
      }
    }
    return true;
  }

    void solveSudoku(vector<vector<char>>& board) {          
      f(board);
    }
};
