#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;cin>>n;
	int count=0;
	string str;cin>>str;
	stack<char> stack;
	for (int i = 0; i < n; i++)
	{	if (i==0){stack.push(str[0]);}
		else if (stack.top()==str[i]){
			count++;
		}
		else{
			stack.push(str[i]);
		}
	}
	cout<<count;
    cout<<endl;
    return 0;
}