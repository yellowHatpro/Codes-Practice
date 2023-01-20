#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        string st;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i]!='*'){
                st.push_back(s[i]);
            } else {
                if (st.size()!=0){
                    
                    st.pop_back();
                }
            }
        }
        return st;
    }
};