#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        map<char,int> m1;
        vector<string> res;
        string s1="qwertyuiop";
        for (int i = 0; i < s1.length(); ++i)
        {
        	m1[s1[i]]++;
        }
        map<char,int> m2;
        string s2 = "asdfghjkl";
        for (int i = 0; i < s2.length(); ++i)
        {
        	m2[s2[i]]++;
        }
        map<char,int> m3;
        string s3="zxcvbnm";
        for (int i = 0; i < s3.length(); ++i)
        {
        	m3[s3[i]]++;
        }
        for (int i = 0; i < words.size(); ++i)
        {
          	char check = tolower(words[i][0]);
			bool b1 = false;
        	bool b2 = false;
        	bool b3 = false;
        	if (m1[check]!=0)
        	{
        		b1 = true;
        	}
        	else if (m2[check]!=0){
        		b2 = true;
        	}
        	else{
        		b3 = true;
        	}
        	for (int j = 0; j < words[i].length(); ++j)
        	{
        		char chk = tolower(words[i][j]);
        		if (b1)
        		{
        			if (m1[chk]==0)
        			{	b1=false;
        				break;
        			}
        		}
        		else if (b2)
        		{
        			if (m2[chk]==0)
        			{	b2=false;
        				break;
        			}
        		}
        		else{
        			if (m3[chk]==0)
        			{	b3=false;
        				break;
        			}
        		}
        		

        	}
        	if (b1)
        	{
        		res.push_back(words[i]);
        	}
        	else if(b2){
        		res.push_back(words[i]);
        	}
        	else if (b3)
        	{
        		res.push_back(words[i]);
        	}
        }
        return res;
    }
};