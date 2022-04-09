#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		string s;cin>>s;
		stack<char> stc;
		map<char,int> m;
		int markedIndex =0;
		for (int i = 0; i < s.length(); ++i){
			if (stc.empty()){
				stc.push(s[i]);
				markedIndex++;
			}
			else{
				if (stc.top()==s[i]){
					
					stc.pop();
					toupper(stc.top());
			
				}
				else{
					stc.top() = toupper(stc.top());
					stc.push(s[i]);
				}
			}
	}
	
		int stc_size = stc.size();
		int max=0;
		while(!stc.empty()){
			
			m[stc.top()]++;
			if (m[stc.top()]>=max)
			{	
				max=m[stc.top()];
			}
			stc.pop();
		}
		
		if (max%2!=0)
		{
			max--;
		}
		cout<<stc_size-max<<endl;

	}
	return 0;
}