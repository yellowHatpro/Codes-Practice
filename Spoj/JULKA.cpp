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
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define mp map
#define ump unordered_map
#define pb emplace_back
#define pii pair<ll,ll>
#define mid(l,r) (l+(r-l)/2)
#define sortall(x) sort(all(x))
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";

//Type define
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<string> vs;

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
	string a,b;cin>>a>>b;
	vi s;
	vi d;
	for (int i = 0; i < a.size(); ++i)
	{
		s.pb(a[i]-'0');
	}
	for (int i = 0; i < b.size(); ++i)
	{
		d.pb(b[i])
	}
}

int main(){
	FIO
	int t=1;
	cin>>t;
	while(t--){
	solve();
	}
	return 0;
}
