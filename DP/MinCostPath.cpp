//Problem Statement: Given an integer matrix of size m*n, you need to find out the value of minimum cost to reach from the cell (0, 0) to (m-1, n-1). From a cell (i, j), you can move in three directions : (i+1, j), (i, j+1) and (i+1, j+1). The cost of a path is defined as the sum of values of each cell through which the path passes.

#include <bits/stdc++.h>
using namespace std;
int  smallest(int x, int y, int z) {

  int smallest = 99999;

  if (x < smallest)
    smallest=x;
  if (y < smallest)
    smallest=y;
  if(z < smallest)
    smallest=z;

  return smallest;
}
//memoization
int minCost(int mat[][3],int m , int n , int dp[][3]){
    if(m<0||n<0){
        return INT_MAX;
    }
    else if(m==0 && n==0){
        return mat[m][n];
    }
    else if (dp[m][n] != -1)
        return dp[m][n];
    else {
    int x = minCost(mat,m-1,n ,dp);
    int y = minCost(mat,m,n-1, dp);
    int z = minCost(mat,m-1,n-1 , dp);
   int ans = smallest(x,y,z)+mat[m][n];
   dp[m][n] = ans;
    return ans;
    }
}
//Min Cost DP
int minCostDP(int mat[][3] , int m , int n){
//int dp[4][4] = {{-1,-1,-1},{-1,-1,-1},{-1,-1,-1},{-1,-1,-1}};
    int dp[m+1][n+1];
    dp[0][0] = mat[0][0];
    for(int i=1;i<=m;i++){
        dp[i][0] = dp[i-1][0]+mat[i][0];
    }
    for(int i=1;i<=n;i++){
        dp[0][i] = dp[0][i-1]+mat[0][i];
    }
    for (int i = 1; i <=m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int temp = smallest(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+mat[i][j];
            dp[i][j] = temp;
        }
     
    }
       return dp[m][n];
}
        
int minCostPath(int **input , int m , int n , int i , int j){
    
    //Base case
    if(i==m-1 && j==n-1){
        return input[i][j];
    }
    if(i>m-1 || j>n-1){
        return INT_MAX;
    }


    //Recursive Calls
    int x = minCostPath(input,m,n,i,j+1);
    int y = minCostPath(input,m,n,i+1,j);
    int z = minCostPath(input,m,n,i+1,j+1);

    //Small Calculation
    int ans = min(x,min(y,z))+input[i][j];
    return ans;
} 
int minCostPath(int **input , int m , int n){
    return minCostPath(input,m,n,0,0);
}



int main(){
    int x=2,y=2;
 
    int mat[3][3] =  { { 1, 2, 3 },
                       { 4, 8, 2 },
                       { 1, 5, 3 } };

    int dp[3][3] = { { -1, -1, -1 },
                     { -1, -1, -1 },
                     { -1, -1, -1 } };
    cout<<minCost(mat,x,y , dp);
    cout<<endl;
    cout<<minCostDP(mat,x,y);

}