#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int i = 0;
        int j = 0 ;
        string s="";
        while(i<str1.size() && j<str2.size()){
        	if (str1[i]==str2[j]){
        		i++;j++;

        	} else {
        		break;
        	}
        }
        if(i==0) return "";
        int size2 = __gcd(i,(int)str1.size());
        
        for(int x = 0; x<size2;x++){
            s+=str2[x];
        }
        string ss = "";
        int times = (int)(str1.size()/str1.size());
        for (int i = 0; i < times; ++i)
        {
        	ss+=s;
        }
        if (ss!=str1){
        	return "";
        }
        return s;
    }
};