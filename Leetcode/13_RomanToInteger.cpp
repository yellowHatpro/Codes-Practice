#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char,int> m;
        int sum=0;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        int i;
        for ( i = s.length()-2;  i >=0; i--){
           if (m[s[i+1]]>m[s[i]])
            {sum+=m[s[i+1]];
              sum-=m[s[i]];
              i--;
            } 
            else{
              sum+=m[s[i+1]];
            }
        }
        if (i==-1) sum+=m[s[0]];
        return sum;
      }
};