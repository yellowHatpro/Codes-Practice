#include <bits/stdc++.h>
using namespace std;

class Solution{
	int isValid(string A);
};

int Solution::isValid(string A) {
	stack<char> s;
	for (int i = 0; i < A.length(); ++i)
	{
		if (A[i]=='(' || A[i]=='[' || A[i]=='{'){
			s.push(A[i]);
		} else {
			if (A[i]==')'){
				if (!s.empty() && s.top()=='('){
					s.pop();
				} else {
					return 0;
				}
			}
			else if (A[i]=='}'){
				if (!s.empty() && s.top()=='{'){
					s.pop();
				} else {
					return 0;
				}
			}
			else if (A[i]==']'){
				if (!s.empty() && s.top()=='['){
					s.pop();
				} else {
					return 0;
				}
			}

		}
	}
	if (s.empty()){
		return 1;
	} else return 0;
}
