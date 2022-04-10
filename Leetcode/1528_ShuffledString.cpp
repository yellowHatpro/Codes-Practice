#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int idx(vector<int> v, int k){
		auto it = find(v.begin(), v.end(), k);
        int res = 0;
		if (it!=v.end())
		{
			 res =  it-v.begin();
		}
        return res;
	}
    string restoreString(string s, vector<int>& indices) {
        string res;
        for (int i = 0; i < s.length(); ++i)
        {
        	res+=s[idx(indices,i)];
        }
        return res;
    }
};

//another way
class Solution2 {
public:
 string restoreString(string s, vector<int>& indices) {
        string res = s;
        for(int i =0; i < indices.size(); ++i)
            res[indices[i]] = s[i];
        return res;
    }
};