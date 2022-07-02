#include <bits/stdc++.h>
using namespace std;
 string longestCommonPrefix (string arr[], int N)
    {
         bool change = false;
        string res = arr[0];
        for (int i = 1; i < N; ++i)
        {
        	int n = min(res.length(),arr[i].length());
        	for (int j = 0; j < n; ++j)
        	{

        		if (res[j]!=arr[i][j] && j!=0)
        		{
        			res = arr[i].substr(0,j);
               change = true;
        			break;
        		}
        		else if (res[j]!=arr[i][j] && j==0){
        			res = "-1";
        			return res;
        		}
        	}
        if (!change)
        {
            res = arr[i].substr(0,n);
            change = false;
        }
        }
        return res;
    }

   int main(int argc, char const *argv[])
   {
   	int n = 5;
   	string arr[5] = {"abcdef","abcdef","abcdefg","ab","abc"};
   	cout<<longestCommonPrefix(arr,n);
   	return 0;
   }