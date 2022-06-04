#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string interpret(string command) {
    	string ans = "";
    	int i = 0;
        while (i<command.length()){
        	if (command[i]=='(')
        	{
        		if (command[i+1]==')')
        		{
        			ans+='o';
        			i+=2;
        		}
        		else{
        			ans+="al";
        			i+=4;
        		}
        	}
        	else{
        		ans+='G';
        		i++;
        	}
        }
        return ans;
    }
};