#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        string s = to_string(k);
        int si = s.size()-1;
        int ni = num.size()-1;
        int carry = 0;
        vector<int> v;
        while(si>=0 && ni>=0){
            
        	int ans = ((num[ni]) + (s[si] - '0' )+ carry)%10;
        	carry = ((num[ni]) +( s[si] - '0') + carry)/10;
        	ni--;si--;
        	v.push_back(ans);
        }
        while(si>=0){
        	v.push_back(((s[si] - '0') + carry)%10);
        	carry = ((s[si] - '0') + carry)/10;
        	si--;
        }
        while(ni>=0){
        	v.push_back(((num[ni]) + carry)%10);
        	carry = ((num[ni]) + carry)/10;
        	ni--;
        }
        if (carry!=0){
        	v.push_back(carry);
        }
        reverse(v.begin(), v.end());
        return v;

    }
};