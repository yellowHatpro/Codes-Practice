#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string token;
        map<char,string> tokens;
        map<string, char> strs;
        int i = 0;
        int cnt = 0;
        while(getline(ss,token,' ')){
            cnt++;
            if (tokens[pattern[i]]==""){
            	if (!strs.count(token)){
                tokens[pattern[i]] = token;	
                strs[token] = pattern[i];
            	} else {
            		return false;
            	}
            } else {
                if (token != tokens[pattern[i]]){
                    return false;
                }
            }
            i++;
        }
        return cnt==pattern.size();
    }
};