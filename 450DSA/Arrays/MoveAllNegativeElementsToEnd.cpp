#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        int l = 0;
        int r = n-1;
        while(l<=r){
        	if (arr[l]<0){
        		swap(arr[l],arr[r--]);
        	}
        	if (arr[r]>0){
        		swap(arr[l++],arr[r]);
        	}
        }
    }
};