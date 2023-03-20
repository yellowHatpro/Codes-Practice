#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz = flowerbed.size();
        int ans = 0;
        for (int i = 0; i < sz; ++i)
        {
        	if (flowerbed[i]==0){
        		bool l0 = i==0 || flowerbed[i-1]==0;
        		bool r0 = i==sz-1 || flowerbed[i+1]==0;
        		if (l0&&r0){
        			ans++;
        			flowerbed[i]=1;
        		}
        	}
        }
        return ans>=n;
    }
};