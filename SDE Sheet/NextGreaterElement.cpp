#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& arr, int n)
{
  vector<int> ans(n);
	stack<int> s;
  for(int i = n-1; i>=0; i--){
    if (s.empty()){
      ans[i] = -1;
    } else {
      while(!s.empty() && arr[i]>=s.top()) s.pop();
      if (s.empty()){
        ans[i] = -1;
      } else{
        ans[i] = s.top();
      }
    }
      s.push(arr[i]);
  }
  return ans;
}
