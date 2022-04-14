#include <bits/stdc++.h>
using namespace std;

/*
Q1. |----|----|----|----|
	|st	 |    |    |    |
	|----|----|----|----|
	|	 |    |    |    |
	|----|----|----|----|
	|	 |    |    |    |
	|----|----|----|----|
	|	 |    |    |fi  |
	|____|____|____|____|
	start to finish all paths and tell all paths count
	go R-right
	   D-down
	  -> - diagonal
*/
int totalPaths=0;
void mazePath(int i, int j, int m, int n, string curr){
	if (i==m-1&&j==n-1){
		cout<<curr<<endl;
		totalPaths++;
		return;
	}
	if (i>=n||j>=n)
	{
		return;
	}
	mazePath(i+1,j,m,n,curr+'D');
	mazePath(i,j+1,m,n,curr+'R');
	mazePath(i+1,j+1,m,n,curr+"->");
}

/*Q2. There are n cells arranged in linear fashion.
You are standing at the 0th cell and want to reach (n-1)th cell.
At each cell you can have 6 possible jumps to make .
In how many ways you can reach to (n-1)th cell. Print the ways.
*/
void printJumps(int n, int i, string curr){

}


//--------------🅜🅐🅘🅝 🅕🅤🅝🅒🅣🅘🅞🅝 🅗🅔🅡🅔------------------------//

int main(){
	// mazePath(0,0,3,3,"");
	// cout<<totalPaths;
	// totalPaths=0;

	return 0;
}