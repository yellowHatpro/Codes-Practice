//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:

  	long long f(int d, int f, int t){
  		vector<vector<long long>> dp(d+1,vector<long long>(t+1,0));
  		dp[0][0] = 1;
  		for (int dice = 1; dice <=d; ++dice)
  		{
  			for (int target = 1; target <= t; ++target)
  			{
  				long long ans = 0;
  				for (int i = 1; i <= f; ++i)
  				{
  					if (target-i>=0)
  						ans+= dp[dice-1][target-i];
  				}
  				dp[dice][target] = ans;
  			}
  		}
  		return dp[d][t];
  	}

    long long noOfWays(int M , int N , int X) {
        return f(N,M,X);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int M,N,X;
        
        cin>>M>>N>>X;

        Solution ob;
        cout << ob.noOfWays(M,N,X) << endl;
    }
    return 0;
}
// } Driver Code Ends