#include <bits/stdc++.h>
using namespace std;
int main(){
	int matrix[5][5]={};
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			/* code */cin>>matrix[i][j];
		}
	}

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			/* code */
			if (matrix[i][j]==1)
			{
				cout<<abs(2-i) +abs(2-j);
			}
		}
	}
cout<<endl;
	return 0;
}