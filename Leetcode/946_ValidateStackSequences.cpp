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