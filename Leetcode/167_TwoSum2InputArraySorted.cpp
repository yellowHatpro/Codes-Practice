#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> v;
        int n = numbers.size();
        for (int i = 0; i< n ; i++){
            int x = target - numbers[i];
            int l = -1; //good
            int r = n-1; //bad
            while(r>l+1){
                int m = (l+r)/2;
                if (numbers[m]>=x) r = m;
                else l = m;
            }
            if (r!=i && numbers[r]==x){
                v.push_back(i+1);
                v.push_back(r+1);
                break;
            }
        }
        sort(v.begin(), v.end());
        return v;
    }
};