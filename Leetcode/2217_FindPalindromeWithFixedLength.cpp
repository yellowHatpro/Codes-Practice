#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
    	int n = queries.size();
        long long power = (intLength%2)  ? intLength/2 : intLength/2 -1 ;
        long long base = pow(10,power);
        vector<long long> v;
        for (auto q: queries) {
        	string a = to_string(base+q-1);
        	string b = a;
        	reverse(b.begin(), b.end());
        	string res =  (intLength%2) ? a+b.substr(1) : a+b;
            if ((res.size())>intLength){
                v.push_back(-1);
                continue;
            }
        	long long ans = stoll(res);
        	v.push_back(ans);
        }
        return v;
    }
};