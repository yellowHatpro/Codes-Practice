#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int sum = 0;
        int st = satisfaction.size()-1;
        for(int i = st; i>=0; i--){
            sum+=satisfaction[i];
            if (sum<0){
                break;
            }
            st--;
        }
        st++;
        int ans = 0;
        int time = 1;
        while (st<satisfaction.size()){
        	ans+=(time*(satisfaction[st]));
            time++;
            st++;
        }
        return ans;
    }
};