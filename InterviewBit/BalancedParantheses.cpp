#include <bits/stdc++.h>
using namespace std;
int solve(string A) {
	stack<char> s;
	for (int i = 0; i < A.length(); ++i)
	{
		if (A[i]==')'){
			if (!s.empty() && s.top()=='('){
				s.pop();
				continue;
			} else {
				return 0;
			}
		}
		s.push(A[i]);
	}
	if (s.empty()){
		return 1;
	} else return 0;

}