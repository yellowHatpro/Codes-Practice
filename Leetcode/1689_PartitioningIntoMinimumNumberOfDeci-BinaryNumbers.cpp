#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPartitions(string n) {
    	int max=0;
    	for (int i = 0; i < n.length(); ++i)
    	{
    		string s;
    		s+=n[i];
    		int curr = stoi(s);
    		if (curr>max)
    		{
    			max = curr;
    		}
    	}
    	return max;

    }
};


class SolutionUsingChar {
public:
    int minPartitions(string n) {
        char tem = '0';
        for(char c:n){
            if(c > tem) { tem = c;}
        }
        return tem-'0';
    }
};
