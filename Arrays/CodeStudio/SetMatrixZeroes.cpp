#include <bits/stdc++.h> 
using namespace std;
void setZeros(vector<vector<int>> &matrix)
{
	int col0 = 1; // this checks if the 0th col is to be filled with 0: 0 -> yes here
	int n = matrix.size();
	int m = matrix[0].size();
	for (int i = 0; i < n; ++i)
	{
		if (matrix[i][0]==0) col0 = 0 ;
		for (int j = 1; j < m; ++j) // start this loop from j = 1
		{
			if (matrix[i][j]==0){
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}

	// Now we have marked which rows and cols we have to make 0, lets go
	for (int i=n-1;i>=0;i--){
		for(int j = m-1; j>=1;j--){
			if (matrix[i][0]==0 || matrix[0][j]==0){
				matrix[i][j] = 0;
			}
		}
		if (col0==0) matrix[i][0] = 0;
	}
	return;
}

int main(){
	vector<vector<int>> matrix={{0,1,2,0},
								{3,4,0,2},
								{1,3,1,5}};
	setZeros(matrix);
	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix[0].size(); ++j)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}