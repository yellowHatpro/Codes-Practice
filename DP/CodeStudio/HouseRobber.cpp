#include <bits/stdc++.h>
using namespace std;
  
int f(vector<int> &nums, int i, vector<int>&dp){
    if (i==0) return nums[0];
    if (i<0) return 0;
    if (dp[i]!=-1) return dp[i];

    int take = f(nums,i-2,dp) + nums[i];
    int notTake  = f(nums, i-1,dp);
    return dp[i] = max(take,notTake);

}

int maximumNonAdjacentSum(vector<int> &nums){
    vector<int> dp(nums.size(),-1);
    return f(nums,nums.size()-1,dp);
}

int maximumNonAdjacentSumDP(vector<int> &nums){
        vector<int> dp(nums.size(),-1);
        dp[0] = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int take = nums[i];
            if (i>1) take += dp[i-2];
            int notTake = dp[i-1];
            dp[i] = max(take, notTake);
        }
        return dp[nums.size()-1];
        
}

//House Robber II

long long fn (vector<long long>& v,int i, vector<long long> &dp){
    if (i==0) return v[i];
    if (i<0) return 0;
    if (dp[i]!=-1) return dp[i];
    long long take = v[i] + fn(v,i-2,dp);
    long long notTake = fn(v,i-1,dp);
    return dp[i] = max(take,notTake);
}

long long houseRobber(vector<int>& valueInHouse)
{     long long n = valueInHouse.size();
      if (n==1) return valueInHouse[0];
      vector<long long> dp1(n-1,-1);
      vector<long long> dp2(n-1,-1);
      vector<long long> a1 = {valueInHouse.begin()+1,valueInHouse.end()};
      vector<long long> a2 = {valueInHouse.begin(),valueInHouse.end()-1};

     long long a = fn(a1,n-2,dp1);
     long long b = fn(a2,n-2,dp2);
     return max(a,b);
}