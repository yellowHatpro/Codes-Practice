#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <vector>
#define ll long long
#define vi vector<int>
using namespace std;
//Top down approach with memoization
int dp[100009];
int arr[100009];
int n,k;
int solve(int idx){
    if(idx==n-1){
        return 0;
    }
    if(dp[idx]!=-1){
        return dp[idx];
    }
    int ans = INT_MAX;
    for(int i=1 ;i<=k;i++){
        if(idx+i>=n){
            break;
        }
        ans = min(ans,solve(idx+i) + abs(arr[idx]-arr[idx+i]));
    }
    return dp[idx] = ans;


}
int main(){
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<solve(0)<<endl;
    return 0;
}
//DP Solution
int main(){
    ll n,k;
    cin>>n>>k;
    vi arr(n,0);
    for (int i = 0; i <= n-1; i++)
    {
        cin>>arr[i];
    }
    vi dp(n,1e18);
    //dp[i] represents minimum cost to reach from stone 1 to stone i
    dp[0] = 0;
    for (int i = 1; i <= n-1; i++)
    {
        for(int j=1;j<=k;j++){
            if(i-j<0) break;
            dp[i] = min(dp[i],dp[i-j]+abs(arr[i]-arr[i-j]));
        }
    }
    
    cout<<dp[n-1];
    return 0;


    
}