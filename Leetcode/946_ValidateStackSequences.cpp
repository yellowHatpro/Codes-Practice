#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
     bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int> stack;
        int j = 0;
        for (int x: pushed) {
            stack.push(x);
            while (stack.size()!=0 && j < n && stack.top() == popped[j]) {
                stack.pop();
                j++;
            }
        }

        return j == n;
    }
};

class Solution2 {
public:
     bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int i = 0;
        int j = 0;
        int n = pushed.size();
        while (i<n){
           while (!s.empty() && j<n && s.top()==popped[j]){
                s.pop();
                j++;
            }
            s.push(pushed[i++]);

        }
        while(j<n){
            if (s.top()!=popped[j++]){
                return false;
            } else {
                s.pop();
            }
        }
        return true;

    }
};