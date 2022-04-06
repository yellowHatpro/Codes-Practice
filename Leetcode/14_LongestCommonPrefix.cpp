#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	int cnt=strs[0].length();
    	string count;
    	string res=strs[0];
        for (int i =1; i < strs.size(); ++i)
        {	int sz = strs[i].length();
        	cnt = res.length();
        	for (int j = 0; j < cnt; ++j)
        	{
        		if (res[j]==strs[i][j])
        			{
        				count+=strs[0][j];
        			}
                
       			else{
        				if (res.length()>count.length())
        				{
        					res=count;
        					count="";
        					break;
        				}
        			}	
        	}
         count="";
        }
        return res;
    }
};