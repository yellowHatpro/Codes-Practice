#include <bits/stdc++.h>
using namespace std;
int main(){

	int a;cin>>a;
	int b;cin>>b;
	for (int i = 1; i <= a; ++i)
	{
		if (i%2==1)
			{
			for (int j =1; j <=b; j++)
		{
			cout<<"#";	
		}
			}
			else if(i%4==2){
				for (int x = 0; x < b-1; ++x)
				{
					cout<<".";	
				}
				cout<<"#";
			}
			else if(i%2==0){
				cout<<"#";
				for (int i = 1; i < b; ++i)
				{
					cout<<".";
				}
			}
			cout<<endl;
		
	}
	return 0;
}