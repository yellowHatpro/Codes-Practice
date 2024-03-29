#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
		int n = chars.size();
		if (n==1) return 1;
	    int i=0,j=0;
	    while(i<n){
	    	int cnt = 1;
	    	while(i<n-1 && chars[i]==chars[i+1]){
	    		cnt++;
	    		i++;
	    	}
	    	chars[j++] = chars[i++];
	    	if (cnt>1){
	    		string cntString = to_string(cnt);
	    		for(char c: cntString){
	    			chars[j++] = c;
	    		}
	    	}
	    }
	    return j;
	}
};