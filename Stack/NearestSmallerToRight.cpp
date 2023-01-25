#include <bits/stdc++.h>
using namespace std;
int main(){
	vector<int> v;
	vector<int> input={1,3,2,4,1,5,2,1};
	stack<int> s;
	for (int i = input.size()-1;i>=0;i--)
	{
		if (s.size()==0){
			v.push_back(-1);
		} else if (s.top()<=input[i]){
			v.push_back(s.top());
		} else if ( s.top() >= input[i]){
			while(s.size()>0 && s.top() >=input[i]){
				s.pop();
			}
			if (s.size()==0){
				v.push_back(-1);
			} else {
				v.push_back(s.top());
			}
		}
		s.push(input[i]);
	}
	reverse(v.begin(), v.end());
	for(int it : v){
		cout<<it<<" ";
	}
	return 0;
}