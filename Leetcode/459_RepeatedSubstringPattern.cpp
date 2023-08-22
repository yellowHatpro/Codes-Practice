#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        if(n<=1)
            return 0;
        string str="";
        for(int i=1;i<n;i++){
            if(s[i]==s[0]){
                str=s.substr(i,n-i)+s.substr(0,i); // if first character matches we put starting part at the end and check if we get the same string.
                if(str==s)
                    return 1;
                str="";
            }   
        }
        return 0;
    }
   };
