// yellowhatpro
#include <bits/stdc++.h>
using namespace std;

//Aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;

//Constants
constexpr ll INF = 2e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 1e9+7;

//Macros
#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define int long long int
#define F first
#define S second
#define pb push_back
#define endl "\n"
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define len(x) ((int) x.size())
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define mid(l,r) (l+(r-l)/2)
#define sortall(x) sort(all(x))
#define print(a) for(auto i: a) cout<<i<<" "; cout<<endl

//Type define
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef map<int, int> mii;

//Math Functions
ll LCM(int a, int b){
	return ((ll)a*b)/__gcd(a,b);
}

ll modpow(ll x, ll n, int m=MOD){
	if (x==0 && n==0) return 0; 
	ll res = 1;
	while(n>0){
		if (n%2){
			res = (res*x) %m;
		}
		x = (x*x)%m;
		n/=2;
	}
	return res;
}

void solve(){
	vector<vector<int>> v(12,vector<int>(12,0));
	int n;cin>>n;
	for (int i = 0; i < n; ++i)
	{
		string s;cin>>s;
		v[s[0]-'a'][s[1]-'a'] +=1;
	}
	// for (int i = 0; i < 12; ++i)
	// {
	// 	for (int j = 0; j < 12; ++j)
	// 	{
	// 			cout<<v[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// cout<<endl;
	int cnt = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j <v.size(); ++j)
		{	if (v[i][j]==0) continue;
			int a_sum = 0;
			int b_sum = 0;
			for (int col = 0; col < v.size(); ++col)
			{	
				if (j!=col){
					a_sum+=v[i][col];
				}
			}
			a_sum*=v[i][j];
			for (int row = 0; row < v.size(); ++row)
			{
				if (i!=row){
					b_sum+=v[row][j];
				}
			}
			b_sum*=v[i][j];
			cnt+=(a_sum+b_sum);
		}
	}
	
	cout<<cnt/2<<endl;
}

int32_t main(){
	FIO
	int t=1;
	cin>>t;
	while(t--){
	solve();
	}
	return 0;
}
