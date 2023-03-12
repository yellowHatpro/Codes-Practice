#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int cnt = 0;
        for(int i =left;i<=right;i++){
        	int len = words[i].size()-1;
        	if ((words[i][0]=='a' || words[i][0]=='e' ||words[i][0]=='i' ||words[i][0]=='o' ||words[i][0]=='u') && (
        		words[i][len]=='a' || words[i][len]=='e' ||words[i][len]=='i' ||words[i][len]=='o' ||words[i][len]=='u')){
        		cnt++;
        	}
        }
        return cnt;
    }
};