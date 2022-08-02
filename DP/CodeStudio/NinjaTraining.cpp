#include <bits/stdc++.h>
using namespace std;
  
int f(int day, vector<vector<int>> &points,vector<vector<int>> &dp, int last){
    if (day==0){
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i!=last){
                maxi = max(maxi,points[0][i]);
            }
        }
        return maxi;
    }
    int maxi = 0;
    if (dp[day][last]!=-1) return dp[day][last];
    for (int i = 0; i < 3; i++)
    {
        if (i!=last){
            int point = f(day-1, points, dp, i) + points[day][i];
            maxi = max(maxi, point);
        }
    }
    return dp[day][last] = maxi;
    
}


int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int>(4,-1));
    int last = 3;
    return f(n-1, points, dp, last  );
}
//DP Implementation later