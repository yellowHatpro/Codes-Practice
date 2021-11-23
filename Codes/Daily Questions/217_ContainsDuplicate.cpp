#include <bits/stdc++.h>
using namespace std;
void main(){
    vector<int> v = {1,2,3,4,5,6,7,8,9,10,10};
    Solution s;


}
//done using sets as well
class Solution {
public:
bool containsDuplicate(vector<int>& nums) {
  unordered_map<int, int> m;
  for(int i=0; i<nums.size();i++){
      if(m.find(nums[i])!=m.end()){
          return true;
      }
      else{
            m[nums[i]]=1;
      }
  }
  return false;
}
};

