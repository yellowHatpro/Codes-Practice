#include<bits/stdc++.h>
using namespace std;
int main()
{ int n;int k; cin>>n; cin>>k;
	int arr[k+1];
	int cnt = 0;

	for (int i = 0; i <= n; ++i)
	{
		string s;cin>>s;
		for (int j= 0; j <s.length(); ++i)
				
			{int curr = int(s[j]);
				if(curr>k){
					break;
				}
				if(curr<=k){
				arr[curr] =1;
			}
			}
			int check =1;
			for (int kd = 0; i <= k; ++i)
				{check =check&arr[kd];
				}
				if(check==1){
					cnt++;
				}	






	cout<<cnt;
	}


    cout<<endl;
    return 0;
}