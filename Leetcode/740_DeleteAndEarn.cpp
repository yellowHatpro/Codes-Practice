#include <bits/stdc++.h>
using namespace std;
class SolutionMine {
public:
    int deleteAndEarn(vector<int>& nums) {
        int  n = nums.size();
        map<int,int> m;
		set<int> s;
        for (int i = 0; i < n; ++i)
        {	s.insert(nums[i]);
        	m[nums[i]]++;
        }
        vector<int> dp(n);
        dp[0] = *s.begin();
        dp[1] = *next(s.begin(),1);

        for (int i = 2; i < n; ++i)
        {
        	dp[i] = max(dp[i-1], *next(s.begin(),i-2)*(m[*next(s.begin(),i-2)]));
        }
        return dp[n-1];
    }
};

//This solution needs to be checked again
class Solution {
public:
  int fun(int num,vector<int>&freq,vector<int>&dp)
{
    dp[0]=freq[0];

    for(int i=1;i<=num;i++)
    {
      int pick=i*freq[i];
      if(i>1)
        pick+=dp[i-2];
      int nonpick=dp[i-1];

      dp[i]=max(pick,nonpick);
    }
    return dp[num];
  }

  int deleteAndEarn(vector<int>& nums)
  {
    int n=nums.size();
    int maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
      if(nums[i]>maxi)
        maxi=nums[i];
    }
    vector<int>freq(maxi+1,0);
    for(int i=0;i<n;i++)
    {
      int num=nums[i];
      freq[num]++;
    }
    vector<int>dp(maxi+1,-1);
    int ans=fun(maxi,freq,dp);
    return ans;
  }
};