#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bestClosingTime(string customers) {
      int n = customers.size(); 
      vector<int> prefixSum(n,0);
      prefixSum[0] = (customers[0]=='Y') ? 1 : -1; 
      for(int i =1; i < n; i++){
        if (customers[i]=='Y') prefixSum[i] = prefixSum[i-1]+1;
        else prefixSum[i] = prefixSum[i-1]-1; 
      }
      int ans = ans;
      int maxe = INT_MIN;
      for(int i = 0; i < n; i++){
        if (prefixSum[i]>maxe){
          maxe = prefixSum[i];
          ans = i;
        }  
      }
      
      return (maxe<=0) ? 0 : ans+1;
    }
};
