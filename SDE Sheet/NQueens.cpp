#include <bits/stdc++.h>
#include <string>
using namespace std;

class Solution {
public:

    bool isPossible(int n, int row, int column, vector<string>& board ){
        //same col
        for(int i=row-1;i>=0;i--){
            if(board[i][column]=='Q'){
                return false;
            }
        }
         //Upper Left Diagonal
    for(int i=row-1,j=column-1;i>=0 && j>=0;i--,j--){
        if(board[i][j]=='Q'){
            return false;
        }
    }
        //Upper Right Diagonal
    for(int i=row-1,j=column+1;i>=0 && j<n;i--,j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }
    return true;
  }

    void f(vector<vector<string>> &res, int i, int n, vector<string> &board){
      if (i==n){
        res.push_back(board);
        return;
      }
      for(int j =0; j < n; j++){
        if(isPossible(n, i, j, board)){
          board[i][j]='Q';
          f(res,i+1,n,board);
          board[i][j]='.';
      }
    }
      
  }

    vector<vector<string>> solveNQueens(int n) {
      vector<vector<string>> res;
      vector<string> board(n);
      string s;
      for(int i = 0; i < n;i++){
        s+=".";
      }
      for(int i =0; i < n; i++){
        board[i] = s;
      }
      f(res,0,n, board);
      return res;
    }
};
