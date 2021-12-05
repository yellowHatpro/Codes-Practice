#include <bits/stdc++.h>
using namespace std;
int knapsack(int *weight , int* values , int n, int maxWeight){
    //Base Case
    if(n==0||maxWeight==0)
        return 0;
    //Recursive calls
    if(weight[0]>maxWeight)
        return knapsack(weight+1,values+1,n-1,maxWeight);//return the case y when we dont include the first item..
    int x = knapsack(weight+1,values+1,n-1,maxWeight-weight[0] )+values[0];
    int y = knapsack(weight+1,values+1,n-1 , maxWeight);
    return max(x,y);
}
//Memoization
int knapsack(int* weight, int* values , int n , int maxWeight , int** mem){
     //Base Case
    if(n==0||maxWeight==0)
        
        return 0;
    //Recursive calls
    if(mem[n][maxWeight]!=-1){
        return mem[n][maxWeight];
    }
    int ans;
    if(weight[0]>maxWeight)
        ans = knapsack(weight+1,values+1,n-1,maxWeight,mem);//return the case y when we dont include the first item..
        else{
    int x = knapsack(weight+1,values+1,n-1,maxWeight-weight[0] ,mem)+values[0];
    int y = knapsack(weight+1,values+1,n-1 , maxWeight,mem);
    ans =  max(x,y);
    mem[n][maxWeight] = ans;
    return ans;}
}

int knapsack(int* weight, int* value, int n, int maxWeight) {
	int **mem = new int*[n+1];

    for(int i=0; i<=n;i++){
       mem[i] = new int[maxWeight+1];
       for(int j=0;j<=maxWeight;j++){
           mem[i][j] = -1;
       }
    }
    return knapsack(weight , value , n , maxWeight , mem);
}


int main(){
    int n,maxWeight;
    cin>>n>>maxWeight;
    int weight[n],values[n];
    for(int i=0;i<n;i++)
        cin>>weight[i];
    for(int i=0;i<n;i++)
        cin>>values[i];
    cout<<knapsack(weight,values,n,maxWeight);
    return 0;
}
