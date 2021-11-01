
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
	#define pb push_back
	#define f first
	#define s second
	
	using namespace std;
	int main()
	{
		std::ios::sync_with_stdio(false);
		int police = 0;
		int crime = 0;
		int n;cin>>n;
		for (int i = 0; i < n; ++i)
		{
			int x =0;
			cin>>x;
			if(police==0 && x==-1){
				crime++;
			}
			else if(x>0){
				police+=x;
			} 
			else if (police!=0 && x==-1){
				police--;
			}
			
		}
		cout<<crime;
	
		return 0;
	}
