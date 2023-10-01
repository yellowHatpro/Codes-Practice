#include <bits/stdc++.h>
using namespace std;
int main(){
	vector<int> v;
	vector<int> input={1,3,2,4};
	stack<int> s;
	for (int i = 0; i<input.size();i++)
	{
		if (s.size()==0){
			v.push_back(-1);
		} else if (s.top()>input[i]){
			v.push_back(s.top());
		} else if ( s.top()<= input[i]){
			while(s.size()>0 && s.top()<=input[i]){
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
	for(int it : v){
		cout<<it<<" ";
	}
	return 0;
}
