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
	int n;cin>>n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}
	vector<int> s = v;
	sortall(s);
	vector<int> r = s;
	reverse(s.begin(), s.end());
	int i =0;
	int j = n-1;
	while(i<j){
		if ((v[i]==s[i] || (v[i]==r[i])) || (v[j]==s[j]) ||(v[j]==r[j])){
			i++;
			j--;
		} else {
			cout<<i<<" "<<j<<endl;
			return;
		}
	}
	cout<<-1<<endl;
	return;
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
