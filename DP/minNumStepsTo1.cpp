#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &dp, int n){
    if (n<=0) return INT_MAX;
    if (n==1) return 0;
    if (dp[n]!=-1) return dp[n];
    int a = f(dp,n-1) ;
    int b = (n%2==0) ? f(dp,n/2) : INT_MAX;
    int c = (n%3==0) ? f(dp,n/3) : INT_MAX;
    return dp[n] = min({a,b,c}) + 1;
}

int countStepsToOne(int n) {
    vector<int> dp(n+1,-1);
    return f(dp,n);
}

int main(){
   cout<<countStepsToOne(4);
}
