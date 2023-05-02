#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string build(string s){
        int c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='#') c=max(0,--c);
            else s[c++]=s[i];
        }
        return s.substr(0,c);
    }
    bool backspaceCompare(string s, string t) {
        return build(s)==build(t);
    }
};