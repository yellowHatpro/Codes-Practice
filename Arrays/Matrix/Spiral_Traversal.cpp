#include<bits/stdc++.h>
using namespace std;
int main()
{
	int row;cin>>row;
	int col;cin>>col;
	int arr[row][col];
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cin>>arr[i][j];
		}
	}

	int top=0;
	int bottom=row-1;
	int left=0;
	int right=col-1;
	while(left<=right && top<=bottom){
		for (int i = left; i <= right; ++i)
		{
			cout<<arr[top][i]<<" ";
		}
		top++;
		for (int i = top; i <=bottom ; ++i)
		{
			cout<<arr[i][right]<<" ";
		}
		right--;
		for (int i = right; i >=left; i--)
		{
			cout<<arr[bottom][i]<<" ";
		}
		bottom--;
		for (int i = bottom; i>=top; i--)
		{
			cout<<arr[i][left]<<" ";
		}
		left++;
	}

    cout<<endl;
    return 0;
}