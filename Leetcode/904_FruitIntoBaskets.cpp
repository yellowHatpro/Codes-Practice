#include <bits/stdc++.h>
using namespace std;
class SolutionOld {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0;
        map<int, int> m;
        int j = 0;
        set<int> s;
        for (int i = 0; i < fruits.size(); ++i){
        
            while(j<fruits.size()){
                if ( (m[fruits[j]]>0) or (int)s.size()<=1 ){
                    m[fruits[j]]++;
                    s.insert(fruits[j]);
                    j++;
                }
                else {                   
                    break;
                }
            }
            ans = max(ans,j-i);
            m[fruits[i]]--;
            if (m[fruits[i]]==0){
                s.erase(fruits[i]);
            }
        }
        return ans;
    }
};

class Solution {
public:
    //pashka method
    bool good(int num){
        return num <=2;
    }


    int totalFruit(vector<int>& fruits){
        int l = 0;
        vector<int> cnt(1000000);
        int num = 0;
        int res = 0;
        for (int r = 0; r < fruits.size()-1; ++r)
        {
           cnt[fruits[r]]++;
            if(cnt[fruits[r]]==1){
                num++;
            }
            while (!good(num)){
                cnt[fruits[l]]--;
                if (cnt[fruits[l]]==0){
                    num--;
                }
                l++;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};