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

int f(int i, int j, int m, vector<vector<int>> &dp, int cnt){
	if (i==0 && j ==0) return cnt;
	if (i<0 || j<0 || m>max(i,j)) return 1e10;
	if (dp[i][j]!=-1) return dp[i][j];
	int a = 1+  f(i,j,m+1,dp,cnt);
	int b = 1+  f(i-m,j,m,dp,cnt);
	int c = 1+  f(i,j-m,m,dp,cnt);
	return dp[i][j] = min({a,b,c});
}

void solve(){
	int a,b;cin>>a>>b;
	int m = 1;
	vector<vector<int>>	dp(a+1,vector<int>(b+1,-1));
	 cout<< f(a,b,m,dp, 0)<<endl;
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
