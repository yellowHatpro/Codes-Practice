
	#include <bits/stdc++.h>
	#include <cstdio>
	#include <cstring>
	#include <cmath>
	#include <cstring>
	#include <chrono>
	#include <complex>
	#define endl "\n"
	#define ll long long int
	#define vi vector<int>
	#define vll vector<ll>
	#define vvi vector < vi >
	#define pii pair<int,int>
	#define pll pair<long long, long long>
	#define mod 1000000007
	#define inf 1000000000000000001;
	#define all(c) c.begin(),c.end()
	#define mp(x,y) make_pair(x,y)
	#define mem(a,val) memset(a,val,sizeof(a))
	#define eb emplace_back
	#define f first
	#define s second
	
	using namespace std;

	void solve(){
		int n;cin>>n;
		string s;cin>>s;
		string res = "";
		bool isAlive = true;
		while(!s.empty()){
			int size = s.size();
			if (isAlive){
				char cur = s[0];
				if (cur =='1'){
					res+=cur;
				} else {
					string curr = "";
					curr +=cur;
					res.insert(0,curr);
				}
				s = s.substr(1,size-1);
			} else {
				char cur = s[size-1];
				if (cur =='1'){
					string curr = "";
					curr +=cur;
					res.insert(0,curr);
				} else {
						res+=cur;
				}
				s = s.substr(0,size-1);

			}
			isAlive = !isAlive;
		}
		cout<<res<<endl;
		return;
	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		int T;
		cin>>T;
		// cin.ignore(); must be there when using getline(cin, s)
		while(T--)
		{
			solve();	
		}
		return 0;
	}
