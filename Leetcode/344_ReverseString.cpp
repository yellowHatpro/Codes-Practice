#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	void reverseStringSupportFn(vector<char>&s, int start, int last){
		if (last<=start)
		{
			return;
		}
		char temp = s[start];
		s[start]=s[last];
		s[last] = temp;
		reverseStringSupportFn(s,start+1,last-1);
	}
    void reverseString(vector<char>& s) {
      if (s.size()<=1)
      {
      	return;
      }
      reverseStringSupportFn(s,0,s.size()-1);
    }
};