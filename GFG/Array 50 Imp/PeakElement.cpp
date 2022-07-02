#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
       int l = 0;
       int r = n-1;
        if (n==1) return 0;
       if(arr[0]>=arr[1]) return 0;
       if (arr[n-1]>arr[n-2]) return n-1;
       
       while(l<=r){
       	int mid = (l+r)/2;
      
       	if (arr[mid]>=arr[mid-1]&&arr[mid]>=arr[mid+1])
       	{
       		return mid;
       	}
       	else if(arr[mid-1]>=arr[mid]){
       		r=mid-1;
       	}
       	else{
       		l=mid+1;
       	}
       
    }
}
};
