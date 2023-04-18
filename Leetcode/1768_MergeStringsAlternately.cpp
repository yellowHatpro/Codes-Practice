#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        int j = 0;
        int n = word1.size();
        int m = word2.size();
        bool flag = true;
        string res = "";
        while(i<n && j <m){
        	if (flag){
        		res+=word1[i++];
        		flag=!flag;
        	} else {
        		res+=word2[j++];
        		flag=!flag;
        	}
        }
        while(i<n){
            res+=word1[i++];
        }
        while(j<m){
            res+=word2[j++];
        }
        return res;
    }
};