#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int minJumps(int arr[], int n){
        int ans = 0;
        int lvl = 0;
        int end = 0;
        for (int i = 0; i < n; ++i)
        {
        
            lvl = max(lvl,i+arr[i]);
           
            if (lvl >= n-1){
                ans++;
              return ans;
            }
            if (i==lvl) return -1;
            if (i == end){
                ans++;
                end = lvl;
            }
        }
        return -1;
    }
};