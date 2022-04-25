#include<bits/stdc++.h>
using namespace std;

int board[11][11];

void nqueen(int n,int row, bool col[], bool diag[], bool reversediag[], string asf){
	//base
	if (row==n)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return;
	}
	for (int column = 0; column < n; ++column)
	{
		if (col[column]==false && diag[row+column]==false&& reversediag[row-column + n-1]==false)
		{
			col[column]=true;
			diag[row+column]=true;
			reversediag[row-column + n-1] = true;
			board[row][column] = 1;
			nqueen(n, row+1,col,diag,reversediag,asf+to_string(row)+"-"+to_string(column)+" ");
			board[row][column] = 0;
			col[column]=false;
			diag[row+column]=false;
			reversediag[row-column + n-1] = false;
			
		}

	}
	
}



int main(){
	int n;cin>>n;
	bool col[n];
	bool diag[n];
	bool reversediag[n];
	for (int i = 0; i < n; ++i)
	{
		col[i]=false;
		diag[i]=false;
		reversediag[i]=false;
	}
	string asf="";
	nqueen(n,0,col,diag,reversediag,asf);
}