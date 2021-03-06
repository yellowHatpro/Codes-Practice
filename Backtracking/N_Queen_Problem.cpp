#include <bits/stdc++.h>
using namespace std;
int board[11][11];

bool isPossible(int n , int row , int column){
    //Same Column
    for(int i=row-1;i>=0;i--){
        if(board[i][column]==1){
            return false;
        }
    }
    //Upper Left Diagonal
    for(int i=row-1,j=column-1;i>=0 && j>=0;i--,j--){
        if(board[i][j]==1){
            return false;
        }
    }

    //Upper Right Diagonal
    for(int i=row-1,j=column+1;i>=0 && j<n;i--,j++){
        if(board[i][j]==1){
            return false;
        }
    }
    return true;
}
void nQueenHelper(int n , int row){
    if(row==n){
        //We have reached some solution.
        //Print the board matrix
        //Return
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
        }
        cout<<endl;
        return;
    }
    //Place it at all possible positions and move to smaller problem
    for(int j=0;j<n;j++){
        if(isPossible(n,row,j)){
            board[row][j]=1;
            nQueenHelper(n,row+1);
            board[row][j]=0;//Backtracking
        }
    }
    return;
}
void placeNQueens(int n){
    memset(board,0,sizeof(board));
    nQueenHelper(n,0);
}
int main(){
    int n;cin>>n;
    placeNQueens(n);
    return 0;
}