#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
     	int si = s.length()-1;
     	int cnt = 0;
     	for (int i = si ; i >= 0; i--)
     	{
     		if (s[i]==' ' && cnt==0)
     		{	
     			continue;
     		}else if (s[i]!=' ' ) {
     			cnt++;
     		}

     		else{ break;}
     	}
     	return cnt;
    }
};