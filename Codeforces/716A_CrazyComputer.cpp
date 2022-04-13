#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	int c;cin>>c;
	int total=0;
	int prev=0;
	for (int i = 0; i < n; ++i)
	{	
		int a;cin>>a;
		if(i==0){
			 prev=a;
			 total++;
		}
		else if(a-prev<=c){
			total++;

		}
		else{
			total=1;

		}

		prev=a;
	}
	cout<<total;
cout<<endl;
	return 0;
}