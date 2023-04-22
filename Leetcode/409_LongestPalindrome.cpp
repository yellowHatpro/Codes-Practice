#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;
        map<char, int> m;
        bool isOdd = false;
        for (int i = 0; i < s.size(); ++i) m[s[i]]++;
        for (auto itr : m){
        	if (itr.second%2) {
                isOdd=true;
                ans+=(itr.second-1);}
        	if (itr.second%2==0) ans+=itr.second;
        }
        return (isOdd) ? ans+1 : ans;
    }
};