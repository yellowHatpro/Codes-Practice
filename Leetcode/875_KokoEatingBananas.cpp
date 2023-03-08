#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
    	int n = piles.size();
		long long r = *max_element(piles.begin(), piles.end());
		int l =1;
		long long ans = r;
		while(l<=r){
			long long mid = l + (r-l)/2;
			long long cnt = 0;
			for (int i = 0; i < n; ++i)
			{
				cnt+=(piles[i]/mid);
                if (piles[i]%mid!=0) cnt++;
			}
			if (cnt>h){
				l = mid+1;
			} else {
				ans = min(ans, mid);
				r = mid-1;
			}
		}
		return ans;

    }
};