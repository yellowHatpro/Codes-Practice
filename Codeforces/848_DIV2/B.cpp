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
	int n,m,d;cin>>n>>m>>d;
	mii p;
	for (int i = 0; i < n; ++i)
	{
		int x;cin>>x;
		p[x] = i+1;
	}
	vi a(m);
	for (int i = 0; i < m; ++i)
	{
		cin>>a[i];
	}
	vi diff;
	for (int i = 1; i < m; ++i)
	{	
		if (p[a[i-1]] - p[a[i]]>0){
			cout<<0<<endl;
			return;
		}
		diff.pb(abs(p[a[i-1]] - p[a[i]]));
	}
	sort(diff.begin(), diff.end(), greater<int>());
	//diff[0] is heighest diff
	int wow=diff[diff.size()-1];
	
	 if (wow>d+1-diff[0] && d<n-1){
		wow = d+1-diff[0];
	} 
	if (wow<0) wow = 0;
	cout<<wow<<endl;
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
