#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int cnt = 0;
        int ans = 0;
        int maxi = 0;
        int n = s.size();
        int i = 0;
        for (; i < n; ++i)
        {
        	if (s[i]=='0'){
        		break;
        	}
        }
        while(i<n){
        	if (s[i]=='0'){
        		i++;
        		cnt++;
        	} else {
        		int j = i;
        		int no1 = 0;
        		while(j<n && s[j]!='0'){
        			j++;
        			no1++;
        		}
        		ans= 2*min(cnt,no1);
        		maxi = max(maxi,ans);
        		cnt=0;
        		i = j;
        	}
        }
        return maxi;
    }
};