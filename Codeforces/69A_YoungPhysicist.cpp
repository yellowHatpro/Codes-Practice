	#include <bits/stdc++.h>	
	using namespace std;
	int main()
	{
		std::ios::sync_with_stdio(false);
		int xsum=0;
		int ysum=0;
		int zsum=0;
		int T;
		cin>>T;
		// cin.ignore(); must be there when using getline(cin, s)
		while(T--)
		{
			int x;cin>>x;xsum+=x;
			int y;cin>>y;ysum+=y;
			int z;cin>>z;zsum+=z;
		}

		if (xsum==0 && ysum==0 && zsum==0)
		{
			cout<<"YES";
		}
		else {
			cout<<"NO";
		}
		

		return 0;
	}
