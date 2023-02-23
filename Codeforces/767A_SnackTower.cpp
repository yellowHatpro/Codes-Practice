#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int curr=n;
    int arr[n+1]={0};
    for(int i=0;i<n;i++)
    {
        int inp;
        cin>>inp;
        arr[inp]++;
        while(arr[curr]) cout<<curr--<<" ";
        cout<<endl;
        }
    return 0;
    }