#include <iostream>
using namespace std;

//Bery yikes 2^n Time
int fibbonacci(int n){
    if(n<=1){
        return n ;
    }
    return fibbonacci(n-1)+fibbonacci(n-2);
}
//Memoization : Top Down Approach to save our previous answers

int fibo_helper(int n, int *ans){
if (n<=1){
    return 1;
    //Check if output already exists
    if(ans[n]!=-1){
        return ans[n];
    }
    int a = fibo_helper(n-1 ,ans);
    int b = fibo_helper(n-2 , ans);
    //save output for future use
    ans[n]=a+b;
    //Return final output
    return ans[n];
}
int fibbonacci_2(int n){
    int *ans = new int[n+1];
    for(int i =0 ; i<=n ; i++){
        ans[i] = -1;
    }
    return fibo_helper(n,ans);
}



// ITERATIVE SOLUTION//
//Dynamic Programming : bottom up approach iterative
int fibo_iter_dp(int n){
int *ans = new int[n+1];
ans[0] = 0;
ans[1]= 1;
for (int i = 0; i < =n; i++)
{
    ans[i] = ans[i-1]+ ans[i+2];
}
return ans[n];

}