#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxVowels(string s, int k) {
        int l = 0;
        int ans = 0;
        int curr = 0;
        int r = 0;
        while ( r < s.size()) {	
        	while((r-l+1)<=k){
        		if (s[r]=='a' ||s[r]=='e' ||s[r]=='i' ||s[r]=='o' ||s[r]=='u') curr++;
				r++;
        	}
        	ans = max(ans,curr);
        	if (s[l]=='a' ||s[l]=='e' ||s[l]=='i' ||s[l]=='o' ||s[l]=='u') curr--;
        	l++;
        }
        return ans;
    }
};