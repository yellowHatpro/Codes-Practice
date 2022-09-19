#include <bits/stdc++.h>
using namespace std;

int hourglassSum(vector<vector<int>> arr) {
    int maxi = INT_MIN;
    int sum = 0;
    for (int i = 0; i < 4; ++i)
    {    
        for (int j = 0; j < 4; ++j)
        {       int sum = 0;
                sum+=arr[i][j];
                sum+=arr[i][j+1];
                sum+=arr[i][j+2];
                sum+=arr[i+1][j+1];
                sum+=arr[i+2][j];
                sum+=arr[i+2][j+1];
                sum+=arr[i+2][j+2];
                maxi = max(maxi,sum);
                
        }
        
    }
    return maxi;
}