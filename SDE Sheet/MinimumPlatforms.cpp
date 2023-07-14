#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int findPlatform(int arr[], int dep[], int n)
    {
      //key move: sort both arr and dep arrays
      sort(arr,arr+n);
      sort(dep,dep+n);
      int platforms = 1;
      int res = 1;
      int i = 1;
      int j = 0;
      while(i<n && j<n){
        if (arr[i] <= dep[j]) {
          platforms++; 
          i++;
        }
        else if (arr[i]>dep[j]) {
          platforms--;
          j++;
        }
        res = max(res,platforms);
    }
    return res;
    }
};
