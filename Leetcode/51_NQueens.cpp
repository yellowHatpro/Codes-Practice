#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> boards;
    vector<string> board;
    bool isPossible(int n, int row, int column){
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
    void nQueenHelper(int n, int row){
        if(row==n){
            //we reached solution
            boards.push_back(board);
            return;
        }
        for(int j=0;j<n;j++){
            if(isPossible(n,row,j)){
                board[row][j]='Q';
                nQueenHelper(n,row+1);
                board[row][j]='.';//Backtracking
            }
        }
        return ;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        for(int i=0;i<n;i++){
            board.push_back(std::string(n, '.'));
        }
         
        nQueenHelper(n,0);
        return boards;
    }
};