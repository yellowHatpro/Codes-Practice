#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int addMinimum(string word) {
     	int cnt = 0;
     	int n = word.size();
     	if (n==1){
     		return 2;
     	}
     	for (int i = 0; i < n-1; ++i)
     	{	
     		if (word[i]==word[i+1]){
     		cnt+=2;
     		continue;
     		}
     		if (word[i]=='a'){
     			if (word[i+1]=='b') continue;
     			else if (word[i+1]=='c') cnt++;
     		}
     		else if (word[i]=='b'){
     			if (word[i+1]=='a') cnt++;
     			else if (word[i+1]=='c') continue;
     		}
     		else if (word[i]=='c'){
     			if (word[i]=='a') continue;
     			else if (word[i]=='b') cnt++;
     		}
     	}
     	if (word[n-1]=='a'){
     		cnt+=2;
     	} else if (word[n-1]=='b'){
     		cnt+=1;
     	}
     	return cnt;
    }
};