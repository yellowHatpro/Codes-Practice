#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
    	if (fruits.size()==1) return fruits[0];
    	int ans = 0;
        map<int, int> m;
        int j = 0;
        for (int i = 0; i < fruits.size(); ++i){
        	while(j<fruits.size()){
        		if (m[fruits[j]]>0 || m.size()<=1 ){
        			m[fruits[j++]]++;
        		}
        			else {
        		break;
        	}
        }
        ans = max(ans,j-i);
        m[fruits[i]]--;
        if (m[fruits[i]]==0){
        	m.erase(fruits[i]);
        }
    }
    return ans;
    }
};