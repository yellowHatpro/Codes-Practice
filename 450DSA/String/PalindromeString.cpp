#include <bits/stdc++.h>
using namespace std;
class Solution{
public:	
	int isPalindrome(string S)
	{
    for(int i = 0; i < S.size()/2; i++){
      if (S[i]!=S[S.size()-1 - i]) return 0;
    }
    return true;
	}

};
