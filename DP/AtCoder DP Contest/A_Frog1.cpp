#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

//Recurrance Relation: f(i) = min(|ai-1 - ai| + f(i-1) , |ai-2 - ai| + f(i-2))

//Memoization Solution

// int arr[100009];
// int n;
// int dp[100009];
// int solve(int idx){
//     if(idx == n-1){
//         return 0;
//     }
//     if(dp[idx]!=-1){
//         return dp[idx]; 
//     }
//     int ans = solve(idx+1) + abs(arr[idx]-arr[idx+1]);
//     if(idx+2<n){
//         ans = min(ans,solve(idx+2) + abs(arr[idx]-arr[idx+2]));
//     }
//     dp[idx] = ans;
//     return ans;
// }

// int main(){
//     cin>>n;
//     memset(dp,-1,sizeof(dp));
//     for (int i = 0; i < n; i++)
//     {
//         cin>>arr[i];
//     }
//     cout<<solve(0);
    
// }

//---------------------------------------------------

//DP Solution
int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    vector<int> dp(n,0);
    //dp[i] represents minimum cost to reach from stone 1 to stone i
    dp[0] = 0;

    if(n==1){
        cout<<dp[0];
        return 0;
    }
    dp[1]=abs(arr[0]-arr[1]);
    for (int i = 2; i < n; i++)
    {
        dp[i]= min(dp[i-1]+abs(arr[i]-arr[i-1]),dp[i-2]+abs(arr[i]-arr[i-2]));
    }
    
    cout<<dp[n-1]<<endl;



    
}