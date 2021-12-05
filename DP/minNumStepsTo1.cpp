#include <bits/stdc++.h>
using namespace std;
int helper(int n , int* arr){
    if(n<=1){
        return 1;   
    }
    if(arr[n]!=-1){
        return arr[n];
    }

    int a = helper(n-1,arr);
    int b = INT_MAX;
    int c= INT_MAX;
    if(n%2==0){
      int b=helper(n/2,arr);
    }
    if(n%3==0){
        int c=helper(n/3,arr);
    }
        return min({a,b,c});


}
int countMinStepsToOne(int n){
    int* arr = new int[n+1];
    for ( int i = 0; i<=n; i++){
        arr[i] = -1;
    }
    return helper(n,arr);
}

int countMinStepsToOneMemoization(int n, int *memoiz){
    int* memoiz= new int[n+1];
    for(int i =0 ; i<=n; i++){
        memoiz[i] = -1;
    }
    if(n<=1){
        return 0;
    }
    if(memoiz[n]!=-1){
        return memoiz[n];
    }
    int x = countMinStepsToOneMemoization(n-1, memoiz);
    int y = INT_MAX;
    int z = INT_MAX;
    if(n%2==0){
        y = countMinStepsToOneMemoization(n/2);
    }
    if(n%3==0){
        z = countMinStepsToOneMemoization(n/3);
    }
    memoiz[n] = min({x,y,z});
    return memoiz[n];



}