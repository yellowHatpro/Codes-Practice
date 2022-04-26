#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool col[17];
	bool diag[17];
	bool rdiag[17];
	int res=0;
	int nQueenHelper(int n, int row){
		if (row==n)
		{   res++;
			return res;
		}
		for (int i = 0; i < n; ++i)
		{
			if (!col[i] && !diag[row+i] && !rdiag[row-i+n-1])
			{
				col[i]=true;
				diag[row+i]=true;
				rdiag[row-i+n-1]=true;
		
				nQueenHelper(n,row+1);
				col[i]=false;
				diag[row+i]=false;
				rdiag[row-i+n-1]=false;
			}

		}
		return res;
	}

    int totalNQueens(int n) {
    	for (int i = 0; i < n; ++i)
    	{
    		col[i]=false;
    		diag[i]=false;
    		rdiag[i]=false;
    	}
       return nQueenHelper(n,0);
    }
};