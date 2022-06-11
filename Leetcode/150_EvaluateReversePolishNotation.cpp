#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string tok: tokens) {
            //If tok size >1 --> its definately an int, if size 1 then check if its b/w 0 to 9 then its int
            if(tok.length()>1 || (tok[0]-'0' >=0 && tok[0]-'9'<=9)) st.push(stoi(tok));
            else {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                int c;
                if(tok=="+") c = a+b;
                else if(tok=="-") c = a-b;
                else if(tok=="*") c = a*b;
                else {
                    if(b==0) c=0;
                    else c = a/b;
                }
                st.push(c);
            }
        }
        int ans = st.top();st.pop();
        return ans;
    }
};