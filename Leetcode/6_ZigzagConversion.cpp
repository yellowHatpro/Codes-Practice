#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> v(numRows,vector<char>(s.size()));
        int total = 0;
        int j = 0;
        if (numRows==0||numRows == 1 || numRows>=s.size()) return s;
        while (total<s.length())
        {	int i = 0;
    		j++;
        	for (; i < numRows; ++i)
        	{	if (total>=s.length()) break;
        		v[i][j]=s[total++];
        	}
        	i--;
        	while(i>1){
        		i--;
        		if (total>=s.length()) break;
        		v[i][++j]=s[total++];
        	}

        }
        string res="";

        for (int i = 0; i < v.size(); ++i)
        {
        	for (int j = 0; j < v[i].size(); ++j)
        	{	
   
        		if (v[i][j]){

        		res+=v[i][j];
        	}
        	}
        	
        }
        return res;
    }
};

int main(){
	string s = "A";
	int n = 1;
	Solution sol = Solution();
	cout<<sol.convert(s,n)<<endl;
}