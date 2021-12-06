#include <bits/stdc++.h>
using namespace std;
int dp[105][105][2];
int f(int n, int k , int first){
    //base case
    if (n==0){
        return 0;
    }
    if(n==1){
        if (k==0){
            return 1; // 0 's bit count is 0 (k is 0 ) so it is true 
        }
        else {
            return 0;
        }
    }
    if(dp[n][k][first]!=-1){
        return dp[n][k][first];
    }

    int result =-1;
    if (first==1){
        result = f(n-1,k-1,1)+f(n-1,k,0);
    }
    else{
        result = f(n-1,k,1)+f(n-1,k,0);
    }
    return dp[n][k][first]=result;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int num,n,k;
        cin>>num>>n>>k;
        memset(dp,-1,sizeof(dp));//initialize dp array with -1 
        int ans = f(n,k,0);
        ans+=f(n,k,1);
        cout<<ans<<endl;
    }
}