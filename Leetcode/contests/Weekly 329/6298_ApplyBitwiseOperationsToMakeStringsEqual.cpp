#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	pair<int,int> count01(string s){
		int zero = 0;
		int one = 0;
		for (int i = 0; i <s.size(); ++i)
		{
			if (s[i]=='0'){
				zero+=1;
			} else {
				one+=1;
			}
		}
		return {zero,one};
	}
    bool makeStringsEqual(string s, string target) {
        pair<int,int> q = count01(s);
        pair<int,int> ans = count01(target);
        if (s==target) return true;
        if (ans.second==0 || q.second ==0) return 0;
        else return 1;
    }
};